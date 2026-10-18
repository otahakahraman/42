import random


def data_alchemist() -> None:
    names = ["Alice", "bob", "Charlie", "dylan", "Emma", "Gregory",
             "john", "kevin", "Liam"]
    print(f"Initial list of players: {names}")
    names_just_cap = [name for name in names if name == name.capitalize()]
    names_cap = [name.capitalize() for name in names]
    print(f"New list with all names capitalized: {names_cap}")
    print(f"New list of capitalized names only: {names_just_cap}\n")
    score_dict = {name: random.randint(0, 1000) for name in names_cap}
    print(f"Score dict: {score_dict}")
    score_ave = sum(score_dict.values())/len(score_dict.values())
    print(f"Score average is {round(score_ave, 2)}")
    high_scores = {name: value for name,
                   value in score_dict.items() if value > score_ave}
    print(f"High scores: {high_scores}")


def main() -> None:
    print("=== Game Data Alchemist ===\n")
    data_alchemist()


if __name__ == "__main__":
    main()
