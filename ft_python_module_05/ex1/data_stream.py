import typing
from abc import ABC, abstractmethod
from typing import Any


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
    def __init__(self):
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
    def __init__(self):
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
    def __init__(self):
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


if __name__ == "__main__":

    print("=== Code Nexus - Data Stream ===\n")
    stream = DataStream()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    random_list = ['Hello world', [3.14, -1, 2.71],
                   [{'log_level': 'WARNING',
                     'log_message': 'Telnet access! Use ssh instead'},
                    {'log_level': 'INFO',
                     'log_message': 'User wil is connected'}], 42,
                   ['Hi', 'five']]
    print("Initialize Data Stream...")
    stream.print_processors_stats()
    print("\nRegistering Numeric Processor\n")
    stream.register_processor(numeric)
    print(f"Send first batch of data on stream: {random_list}")
    stream.process_stream(random_list)
    stream.print_processors_stats()
    print("Registering other data processors\nSend the same batch again")
    stream.register_processor(text)
    stream.register_processor(log)
    stream.process_stream(random_list)
    stream.print_processors_stats()
    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    for i in range(3):
        numeric.output()
    for i in range(2):
        text.output()
    for i in range(1):
        log.output()
    stream.print_processors_stats()
