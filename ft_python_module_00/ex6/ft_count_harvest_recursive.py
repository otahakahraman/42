def ft_count_harvest_recursive() -> None:
    def count_day(current: int, total: int) -> None:
        if current > total:
            return
        print(f"Day {current}")
        count_day(current + 1, total)
    total = int(input("Days until harvest: "))
    count_day(1, total)
    print("Harvest time!")
