def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    q = quantity

    if (unit == "packets"):
        print(f"{seed_type.capitalize()} seeds: {q} packets available")
    elif (unit == "grams"):
        print(f"{seed_type.capitalize()} seeds: {q} grams total")
    elif (unit == "area"):
        print(f"{seed_type.capitalize()} seeds: covers {q} square meters")
    else:
        print("Unknown unit type")
