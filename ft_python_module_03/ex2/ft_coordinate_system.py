import math 

def get_player_pos() -> None:
    print("Get a first set of coordinates")
    while True:
        try:
            coor = input("Enter new coordinates as floats in format 'x,y,z': ")
            x, y, z = coor.split(",")
            x = float(x)
            y = float(y)
            z = float(z)

            print(f"Got a first tuple: ({x}, {y}, {z})")
            print(f"It includes: X={x}, Y={y}, Z={z}")
            square = math.sqrt(x ** 2 + y ** 2 + z ** 2)
            print(f"Distance to center: {square:.4f}")

            break
        except ValueError:
            print("Invalid syntax")
    print("\nGet a second set of coordinates")
    while True:
        coor2 = input("Enter new coordinates as floats in format 'x,y,z': ")
        x2, y2, z2 = coor2.split(",")
        try:
            x2 = float(x2)
        except:
            print(f"Error on parameter '{x2}': could not convert string to float: '{x2}'")
            continue
        try:
            y2 = float(y2)
        except:
            print(f"Error on parameter '{y2}': could not convert string to float: '{y2}'")
            continue
        try:
            z2 = float(z2)
        except:
            print(f"Error on parameter '{z2}': could not convert string to float: '{z2}'")
            continue
        break

    dist = math.sqrt(((x - x2) ** 2) + ((z - z2) ** 2) + ((y - y2) ** 2))
    print(f"Distance between the 2 sets of coordinates: {dist:.4f}")


def main() -> None:
    print("=== Game Coordinate System ===\n")
    get_player_pos()
if __name__ == "__main__":
    main()