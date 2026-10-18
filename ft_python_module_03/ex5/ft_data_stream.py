import random
import typing


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    names = ["bob", "alice", "dylan", "charlie"]
    actions = ["run", "grab", "eat", "sleep", "move",
               "climb", "swim", "release", "use"]
    while True:
        action = random.choice(actions)
        name = random.choice(names)
        yield (name, action)


def consume_event(my_list: list[tuple[str, str]]
                  ) -> typing.Generator[tuple[str, str], None, None]:
    while len(my_list) > 0:
        index = random.randrange(len(my_list))
        event = my_list.pop(index)
        yield event


def data_stream() -> None:
    gen = gen_event()
    for i in range(1000):
        name, action = next(gen)
        print(f"Event {i}: Player {name} did action {action}")
    my_list = []
    for i in range(10):
        name, action = next(gen)
        my_list.append((name, action))
    print(f"Built list of 10 events: {my_list}")
    for event in consume_event(my_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {my_list}")


def main() -> None:
    print("=== Game Data Stream Processor ===")
    data_stream()


if __name__ == "__main__":
    main()
