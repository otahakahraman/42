class Plant():
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    @property
    def cn(self) -> str:
        return self._name.capitalize()

    def show(self) -> None:
        print(f"{self.cn}: {self._height:.1f}cm, {self._age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False

    def bloom(self) -> None:
        if self._bloomed is False:
            self._bloomed = True

    def show(self) -> None:
        super().show()
        if self._bloomed is False:
            print(f" Color: {self._color}")
            print(f" {self.cn} has not bloomed yet")
        else:
            print(f" Color: {self._color}")
            print(f" {self.cn} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(f"Tree {self.cn} now produces a shade of "
              f"{self._height:.1f}cm long and "
              f"{self._trunk_diameter:.1f}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter:.1f}cm")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, growth_rate: float) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = 0
        self._growth_rate = growth_rate

    def age(self) -> None:
        self._age += 1
        self._nutritional_value += 1

    def grow(self) -> None:
        self._height += self._growth_rate

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self._harvest_season.capitalize()}")
        print(f" Nutritional value: {self._nutritional_value}")


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("rose", 15, 10, "red")
    rose.show()
    rose.bloom()
    rose.show()
    print()
    print("=== Tree")
    oak = Tree("oak", 200, 365, 5)
    oak.show()
    oak.produce_shade()
    print()
    print("=== Vegetable")
    tomato = Vegetable("tomato", 5, 10, "April", 2.1)
    tomato.show()
    for _ in range(20):
        tomato.age()
        tomato.grow()
    tomato.show()


if __name__ == "__main__":
    main()
