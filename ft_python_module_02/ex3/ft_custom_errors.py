class GardenError(Exception):
    def __init__(self, message="General garden error"):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message="Unknown water error"):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error"):
        super().__init__(message)


def plant_error() -> None:
    raise PlantError("The tomato plant is wilting!")


def water_error() -> None:
    raise WaterError("Not enough water in the tank!")


def test_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===\n")
    try:
        print("Testing PlantError...")
        plant_error()
    except PlantError as err:
        print(f"Caught PlantError: {err}\n")

    try:
        print("Testing WaterError...")
        water_error()
    except WaterError as err:
        print(f"Caught WaterError: {err}\n")

    func = [plant_error, water_error]
    print("Testing catching all garden errors...")

    for i in func:
        try:
            i()
        except GardenError as err:
            print(f"Caught GardenError: {err}")
    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
