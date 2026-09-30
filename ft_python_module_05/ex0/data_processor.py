from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    def __init__(self) -> None:
        super().__init__()
        self.storage: list[str] = []
        self.counter: int = 0
        self.rank: int = 0

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
    def validate(self, data: Any) -> bool:
        return (isinstance(data, str) or (isinstance(data, list)
                and all(isinstance(x, str) for x in data)))

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        strings = data if isinstance(data, list) else [data]
        for string in strings:
            self.storage.append(string)
            self.counter += 1


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        def is_valid_dict(d: Any) -> bool:
            return (isinstance(d, dict) and all(isinstance(k, str)
                    and isinstance(v, str) for k, v in d.items()))
        return (is_valid_dict(data) or (isinstance(data, list)
                and all(is_valid_dict(x) for x in data)))

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        dicts = data if isinstance(data, list) else [data]
        for d in dicts:
            self.storage.append(f"{d['log_level']}: {d['log_message']}")
            self.counter += 1


if __name__ == "__main__":
    numeric = NumericProcessor()
    numeric_num = 42
    numeric_false_str = "foo"
    numeric_str = "Hello"
    numeric_list: list[int | float] = [1, 2, 3, 4, 5]
    numeric_extr = 3

    text = TextProcessor()
    text_num = 42
    text_list = ['Hello', 'Nexus', 'World']
    text_extr = 1

    log = LogProcessor()
    log_str = "Hello"
    log_dict: list[dict[str, str]] = [{"log_level": "NOTICE",
                                       "log_message": "Connection to server"},
                                      {"log_level": "ERROR",
                                       "log_message": "Unauthorized access!!"}]
    log_extr = 2
    print("=== Code Nexus - Data Processor ===\n"
          "\nTesting Numeric Processor...")
    print(f" Trying to validate input '{numeric_num}'"
          f": {numeric.validate(numeric_num)}")
    print(f" Trying to validate input '{numeric_str}'"
          f": {numeric.validate(numeric_str)}")
    print(f" Test invalid ingestion of string"
          f"'{numeric_false_str}' without prior validation:")
    try:
        numeric.ingest(numeric_false_str)
    except ValueError as e:
        print(f" Got exception: {e}")
    print(f" Processing data: {numeric_list}")
    print(f" Extracting {numeric_extr} values...")
    numeric.ingest(numeric_list)

    for i in range(numeric_extr):
        numeric_out1, numeric_out2 = numeric.output()
        print(f" Numeric value {numeric_out1}: {numeric_out2}")
    print("\nTesting Text Processor...")
    print(f" Trying to validate input '{text_num}': {text.validate(text_num)}")
    print(f" Processing data: {text_list}")
    print(f" Extracting {text_extr} value...")
    text.ingest(text_list)

    for i in range(text_extr):
        text_out1, text_out2 = text.output()
        print(f" Text value {text_out1}: {text_out2}")

    print("\nTesting Log Processor...")
    print(f" Trying to validate input '{log_str}': {log.validate(log_str)}")

    print(f" Processing data: {log_dict}")
    print(f" Extracting {log_extr} values...")

    log.ingest(log_dict)

    for i in range(log_extr):
        log_out1, log_out2 = log.output()
        print(f" Log entry {log_out1}: {log_out2}")
