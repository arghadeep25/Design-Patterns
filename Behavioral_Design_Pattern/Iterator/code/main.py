from abc import ABC, abstractmethod
from typing import List, Union


# Iterator interface
class Iterator(ABC):
    @abstractmethod
    def has_next(self) -> bool:
        pass

    @abstractmethod
    def next(self) -> Union[str, int]:
        pass


# Aggregate interface
class Iterable(ABC):
    @abstractmethod
    def create_iterator(self) -> "Iterator":
        pass


# Concrete Iterator
class ConcreteIterator(Iterator):
    def __init__(self, collection: List[Union[str, int]]) -> None:
        self.collection: List[Union[str, int]] = collection
        self.position: int = 0

    def has_next(self) -> bool:
        return self.position < len(self.collection)

    def next(self) -> Union[str, int]:
        if self.has_next():
            value: Union[str, int] = self.collection[self.position]
            self.position += 1
            return value
        raise StopIteration("No more elements.")


# Concrete collection
class ConcreteCollection(Iterable):
    def __init__(self) -> None:
        self.items: List[Union[str, int]] = []

    def add_items(self, item: Union[str, int]) -> None:
        self.items.append(item)

    def create_iterator(self) -> ConcreteIterator:
        return ConcreteIterator(self.items)


def main():
    collection = ConcreteCollection()
    collection.add_items(1)
    collection.add_items(2)
    collection.add_items(3)

    iterator: ConcreteIterator = collection.create_iterator()
    print("First Iteration:")
    while iterator.has_next():
        print(iterator.next())

    # Adding new items and creating a new iterator
    collection.add_items("Imagine Dragons")
    collection.add_items("Linkin Park")
    collection.add_items("Coldplay")

    iterator = (
        collection.create_iterator()
    )  # Create a new iterator for the updated collection
    print("\nSecond Iteration:")
    while iterator.has_next():
        print(iterator.next())


if __name__ == "__main__":
    main()
