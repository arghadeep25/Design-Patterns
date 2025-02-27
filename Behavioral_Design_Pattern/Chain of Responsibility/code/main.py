from abc import ABC


class Handler(ABC):
    def __init__(self) -> None:
        self.next = None

    def set_next(self, next_handler) -> None:
        self.next = next_handler

    def handle_request(self, level: int) -> None:
        if self.next:
            self.next.handle_request(level)


class JuniorSupport(Handler):
    def handle_request(self, level: int) -> None:
        if level <= 1:
            print(f"Junior Support: Handling request at level {level}")
        else:
            if next:
                next.handle_request(level)


class SeniorSupport(Handler):
    def handle_request(self, level: int) -> None:
        if level <= 2:
            print(f"Senior Support: Handling request at level {level}")
        else:
            if next:
                next.handle_request(level)


class ManagerSupport(Handler):
    def handle_request(self, level: int) -> None:
        print(f"Manager Support: Handling request at level {level}")


def main() -> None:
    junior = JuniorSupport()
    senior = SeniorSupport()
    manager = ManagerSupport()

    junior.set_next(senior)
    senior.set_next(manager)

    print("Client sending request at level 1")
    junior.handle_request(1)
    print("Client sending request at level 2")
    senior.handle_request(2)
    print("Client sending request at level 3")
    manager.handle_request(3)


if __name__ == "__main__":
    main()
