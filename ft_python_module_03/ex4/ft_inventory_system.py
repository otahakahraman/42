import sys


def my_split(text: str, sep: str) -> list[str]:
    parts: list[str] = []
    current = ""
    for ch in text:
        if ch == sep:
            parts = parts + [current]
            current = ""
        else:
            current += ch
    parts = parts + [current]
    return parts


def inventory_system() -> None:
    inventory: dict[str, int] = {}

    for arg in sys.argv[1:]:
        parts = my_split(arg, ":")
        if len(parts) != 2 or len(parts[0]) == 0:
            print(f"Error - invalid parameter '{arg}'")
            continue
        key = parts[0]
        if key in inventory:
            print(f"Redundant item '{key}' - discarding")
            continue
        try:
            quantity = int(parts[1])
        except ValueError as e:
            print(f"Quantity error for '{key}': {e}")
            continue
        inventory.update({key: quantity})

    item_list = list(inventory.keys())
    total = sum(inventory.values())

    print(f"Got inventory: {inventory}")
    print(f"Item list: {item_list}")
    print(f"Total quantity of the {len(inventory)} items: {total}")

    if total > 0:
        for item in inventory:
            percent = round(inventory[item] * 100 / total, 1)
            print(f"Item {item} represents {percent}%")

    if len(inventory) > 0:
        max_key = item_list[0]
        min_key = item_list[0]
        for item in inventory:
            if inventory[item] > inventory[max_key]:
                max_key = item
            if inventory[item] < inventory[min_key]:
                min_key = item
        print(f"Item most abundant: {max_key} "
              f"with quantity {inventory[max_key]}")
        print(f"Item least abundant: {min_key} "
              f"with quantity {inventory[min_key]}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory_system()


if __name__ == "__main__":
    main()
