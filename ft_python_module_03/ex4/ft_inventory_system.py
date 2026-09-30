import sys

def inventory_sys() -> None:
    Inventory={
        "sword":0,
        "potion":0,
        "shield":0,
        "armor":0,
        "helmet":0,
        "sword":0,
        "key":0,
        "magic_item":0,
        "meat":0,
        "fruit":0,
        "water":0,
        "medicine":0,
        "bread":0,
        "bow":0,
        "axe":0
                }
    list_use=set()
    listed=set(sys.argv[1:])
    list_inventory={}
    for i in listed:
        try:
            name,amount=i.split(":")
            if name not in Inventory: 
                print(f"Error - invalid parameter '{name}'")
                continue
            if name in list_use:
                print(f"Redundant item '{name}' - discarding")
                continue
            list_inventory[name]=int(amount)
            list_use.add(name)
        except ValueError as err:
            if ":" not in i:
                print(f"Error - invalid parameter '{i}'")
            else:
                print(f"Quantity error for '{name}': {err}")

    inv_names=list(list_inventory.keys())
    inv_values=list(list_inventory.values())
    print(f"Got inventory: {list_inventory}")
    print(f"Item list: {inv_names}")
    print(f"Total quantity of the {len(inv_names)} items: 12")

    for i in list_inventory:
        print(f"Item {i.keys()} represents 8.3%")
def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory_sys()

if __name__ == "__main__":
    main()