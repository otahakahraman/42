def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        10/0
    elif operation_number == 2:
        open("/non/existent/file")
    elif operation_number == 3:
        "string" + 5
    elif operation_number == 4:
        print("Operation completed successfully")


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")

    for i in range(5):
        print(f"Testing operation {i}...")
        try:
            garden_operations(i)
        except (ValueError, ZeroDivisionError, TypeError, FileNotFoundError) as err:
            print(f"Caught {err.__class__.__name__}: {err}")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
