def ft_water_reminder() -> None:
    counter = int(input("Days since last watering: "))
    if counter > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
