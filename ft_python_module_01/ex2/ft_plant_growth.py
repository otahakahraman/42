class Plant():
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self._age = age
        self.growth_rate = 0.8  # sabit veya parametre

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self._age} days old")

    def grow(self) -> None:
        self.height = round(self.height + self.growth_rate, 1)

    def age(self) -> None:
        self._age += 1


def main() -> None:
    plant1 = Plant("Rose", 25, 30)
    print("=== Garden Plant Growth ===")
    plant1.show()
    start_height = plant1.height
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant1.grow()
        plant1.age()
        plant1.show()
    print(f"Growth this week: {round(plant1.height - start_height, 1)}cm")


if __name__ == "__main__":
    main()
