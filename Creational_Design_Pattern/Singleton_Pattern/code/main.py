
from typing import Any
from threading import Lock, Thread


class SingletonMeta(type):
    """
    SingletonMeta Declaring metaclass

    Args:
        type (_type_): None

    Returns:
        _type_: class instance
    """
    _instances = {}
    _lock: Lock = Lock()

    def __call__(cls, *args: Any, **kwargs: Any) -> Any:
        with cls._lock:
            if cls not in cls._instances:
                instance = super().__call__(*args, **kwargs)
                cls._instances[cls] = instance
        return cls._instances[cls]


class Singleton(metaclass=SingletonMeta):
    """
    Singleton Singleton class

    Args:
        metaclass (_type_, optional): _description_. Defaults to SingletonMeta.
    """
    value: str = None

    def __init__(self, value: str) -> None:
        self.value = value

    def bs(self):
        pass


def test_singleton(value: str) -> None:
    singleton: Singleton = Singleton(value)
    print(singleton.value)


def main():
    process1: Thread = Thread(target=test_singleton, args=("foo",))
    process2: Thread = Thread(target=test_singleton, args=("bar",))
    process1.start()
    process2.start()


if __name__ == "__main__":
    main()
