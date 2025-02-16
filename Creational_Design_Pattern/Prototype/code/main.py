from abc import ABC, abstractmethod
from copy import deepcopy


# Prototype interface
class Shape(ABC):
    @abstractmethod
    def clone(self) -> None:
        pass

    @abstractmethod
    def draw(self) -> None:
        pass


# Concrete Prototype: Rectangle
class Rectangle(Shape):
    def __init__(self, color: str) -> None:
        self.color: str = color

    def clone(self) -> Shape:
        return deepcopy(self)

    def draw(self) -> None:
        print(f"Drawing Rectangle of color: {self.color}")


# Concrete Prototype: Circle
class Circle(Shape):
    def __init__(self, color: str) -> None:
        self.color: str = color

    def clone(self) -> Shape:
        return deepcopy(self)

    def draw(self) -> None:
        print(f"Drawing Rectangle of color: {self.color}")


# Client interface
def main() -> None:
    rectangle = Rectangle("green")
    rectangle.draw()

    circle = Circle("red")
    circle.draw()

    rectangle_clone: Rectangle = rectangle.clone()
    rectangle_clone.draw()

    circle_clone: Circle = circle.clone()
    circle_clone.draw()


if __name__ == "__main__":
    main()
