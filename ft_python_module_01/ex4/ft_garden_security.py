class Plant():
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        if age < 0:
            print("Error, age can't be negative\n")
            self._age = 0
        else:
            self._age = age
        if height < 0:
            print("Error, height can't be negative\n")
            self._height = 0.0
        else:
            self._height = height

    def get_name(self) -> str:
        return self._name.capitalize()

    def get_age(self) -> int:
        return self._age

    def get_height(self) -> float:
        return self._height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.get_name()}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {self._age} days")

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.get_name()}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {self._height}cm")

    def show(self) -> None:
        print(f"{self.get_name()}: {self._height:.1f}cm, {self._age} days old")


def main() -> None:
    print("=== Garden Security System ===")
    plant1 = Plant("Rose", 15, 10)
    print("Plant created: ", end="")
    plant1.show()
    print()
    plant1.set_height(25)
    plant1.set_age(30)
    print()
    plant1.set_height(-5)
    plant1.set_age(-5)
    print()
    print("Current state: ", end="")
    plant1.show()


if __name__ == "__main__":
    main()
