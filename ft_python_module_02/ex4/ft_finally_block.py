class PlantError(Exception):
    def __init__(self, message="Unknown plant error"):
        super().__init__(message)


def water_plant(plant_name: str) -> str:
    if plant_name == plant_name.capitalize():
        return plant_name
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("=== Garden Watering System ===\n")
    print("Testing valid plants...\nOpening watering system")
    try:
        print(f"Watering {water_plant('Tomato')}: [OK]")
        print(f"Watering {water_plant('Lettuce')}: [OK]")
        print(f"Watering {water_plant('Carrots')}: [OK]")
    except PlantError as err:
        print(f"Caught PlantError: {err}")
    finally:
        print("Closing watering system\n")

    print("Testing invalid plants...\nOpening watering system")
    try:
        print(f"Watering {water_plant('Tomato')}: [OK]")
        print(f"Watering {water_plant('lettuce')}: [OK]")
        print(f"Watering {water_plant('Carrots')}: [OK]")
    except PlantError as err:
        print(f"Caught PlantError: {err}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system\n")
        print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
