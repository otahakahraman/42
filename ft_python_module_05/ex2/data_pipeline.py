import typing
from abc import ABC, abstractmethod
from typing import Any, Protocol


class DataProcessor(ABC):
    def __init__(self) -> None:
        super().__init__()
        self.storage: list[str] = []
        self.counter: int = 0
        self.rank: int = 0
        self.name: str = ""

    @abstractmethod
    def validate(self, data: Any) -> bool:
        ...

    @abstractmethod
    def ingest(self, data: Any) -> None:
        ...

    def output(self) -> tuple[int, str]:
        value = self.storage.pop(0)
        rank = self.rank
        self.rank += 1
        return (rank, value)


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()
        self.name = "Numeric Processor"

    def validate(self, data: Any) -> bool:
        return (isinstance(data, (int, float)) or (isinstance(data, list)
                and all(isinstance(x, (float, int)) for x in data)))

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        characters = data if isinstance(data, list) else [data]

        for character in characters:
            self.storage.append(str(character))
            self.counter += 1


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()
        self.name = "Text Processor"

    def validate(self, data: Any) -> bool:
        return (isinstance(data, str) or (isinstance(data, list)
                and all(isinstance(x, str)for x in data)))

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        strings = data if isinstance(data, list) else [data]
        for string in strings:
            self.storage.append(string)
            self.counter += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()
        self.name = "Log Processor"

    def validate(self, data: Any) -> bool:
        def is_valid_dict(d: Any) -> bool:
            return isinstance(d, dict) and all(isinstance(
                k, str) and isinstance(v, str) for k, v in d.items())
        return is_valid_dict(data) or (isinstance(
            data, list) and all(is_valid_dict(x) for x in data))

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        dicts = data if isinstance(data, list) else [data]
        for d in dicts:
            self.storage.append(f"{d['log_level']}: {d['log_message']}")
            self.counter += 1


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataStream():
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for i in stream:
            for j in self.processors:

                if j.validate(i):
                    j.ingest(i)
                    break
            else:
                print(
                    f"DataStream error - Can't process element in stream: {i}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return
        for item in self.processors:
            print(
                f"{item.name}: total {item.counter} items processed, "
                f"remaining {len(item.storage)} on processor")
        print("")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self.processors:
            output_datas = []
            for i in range(min(nb, len(processor.storage))):
                output_datas.append(processor.output())
            plugin.process_output(output_datas)


class CSVPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values = []
        for rank, value in data:
            values.append(value)
        seperator = ","
        res = seperator.join(values)
        print("CSV Output:")
        print(res)


class JSONPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values = []
        for rank, value in data:
            values.append(f'"item_{rank}": "{value}"')
        separator = ","
        res = "{" + separator.join(values) + "}"
        print("JSON Output:")
        print(res)


if __name__ == "__main__":
    stream = DataStream()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    random_list = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING',
             'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil isconnected'},
        ],
        42,
        ['Hi', 'five'],
    ]

    random_list2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {'log_level': 'ERROR', 'log_message': '500 server crash'},
            {'log_level': 'NOTICE',
             'log_message': 'Certificate expires in 10 days'},
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello',
    ]
    print("=== Code Nexus - Data Pipeline ===\n")
    print("Initialize Data Stream...\n")
    stream.print_processors_stats()
    print("\nRegistering Processors\n")
    stream.register_processor(numeric)
    stream.register_processor(text)
    stream.register_processor(log)
    print(f"Send first batch of data on stream: {random_list}\n")
    stream.process_stream(random_list)
    stream.print_processors_stats()
    print("Send 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, CSVPlugin())
    stream.print_processors_stats()
    print(f"Send another batch of data: {random_list2}")
    stream.process_stream(random_list2)
    stream.print_processors_stats()
    print("Send 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JSONPlugin())
    stream.print_processors_stats()
