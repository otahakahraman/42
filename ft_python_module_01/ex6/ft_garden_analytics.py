class Plant():
    class Statistics:
        def __init__(self) -> None:
            self._s_age = 0
            self._s_grow = 0
            self._s_show = 0

        def inc_age(self) -> None:
            self._s_age += 1

        def inc_grow(self) -> None:
            self._s_grow += 1

        def inc_show(self) -> None:
            self._s_show += 1

        def stats(self) -> None:
            s = "Stats: "
            g = " grow, "
            a = " age, "
            print(f"{s}{self._s_grow}{g}{self._s_age}{a}{self._s_show} show")

    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age
        self._stats = Plant.Statistics()
        self.growth_rate = 1.0

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0, 0)

    @staticmethod
    def check_year_old(days: int) -> bool:
        return days > 365

    def age(self) -> None:
        self._age += 1
        self._stats.inc_age()

    def grow(self) -> None:
        self._height += self.growth_rate
        self._stats.inc_grow()

    @property
    def cn(self) -> str:
        return self._name.capitalize()

    def show(self) -> None:
        print(f"{self.cn}: {self._height:.1f}cm, {self._age} days old")
        self._stats.inc_show()

    def stats(self) -> None:
        self._stats.stats()


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
        self._stats_shade = 0

    def produce_shade(self) -> None:
        print(f"Tree {self.cn} now produces a shade of "
              f"{self._height:.1f}cm long and "
              f"{self._trunk_diameter:.1f}cm wide.")
        self._stats_shade += 1

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter:.1f}cm")

    def stats(self) -> None:
        self._stats.stats()
        print(f"{self._stats_shade} shade")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seed = 0

    def seed_add(self, seed_amount) -> None:
        self._seed += seed_amount

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self._seed}")


def display_stats(plant: Plant) -> None:
    plant.stats()


def main() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.check_year_old(30)}")
    print(f"Is 400 days more than a year? -> {Plant.check_year_old(400)}")

    print("\n=== Flower")
    rose = Flower("rose", 15, 10, "red")
    rose.show()
    print("[statistics for Rose]")
    display_stats(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    print("[statistics for Rose]")
    display_stats(rose)
    print("\n=== Tree")
    oak = Tree("oak", 200, 365, 5)
    oak.show()
    print("[statistics for Oak]")
    display_stats(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print("[statistics for Oak]")
    display_stats(oak)
    print("\n=== Seed")
    sunflower = Seed("sunflower", 80, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.bloom()
    sunflower.age()
    sunflower.grow()
    sunflower.seed_add(42)
    sunflower.show()
    print("[statistics for Sunflower]")
    display_stats(sunflower)

    print("\n=== Anonymous")
    uk_plant = Plant.anonymous()
    uk_plant.show()
    print("[statistics for Unknown plant]")
    display_stats(uk_plant)


if __name__ == "__main__":
    main()
