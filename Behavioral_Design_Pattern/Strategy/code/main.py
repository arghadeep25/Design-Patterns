from abc import ABC, abstractmethod


# Strategy Interface
class NavigationStrategy(ABC):
    @abstractmethod
    def calculate_route(self) -> None:
        pass


# Concrete Strategy: Car
class CarNavigation(NavigationStrategy):
    def calculate_route(self) -> None:
        print("Calculating route for cars")


# Concrete Strategy: Bike
class BikeNavigation(NavigationStrategy):
    def calculate_route(self) -> None:
        print("Calculating route for bikes")


# Concrete Strategy: Walk
class WalkNavigation(NavigationStrategy):
    def calculate_route(self) -> None:
        print("Calculating route for pedestrians")


# Context Class
class NavigationContext:
    def __init__(self) -> None:
        self.strategy: NavigationStrategy = None

    def set_strategy(self, strategy: NavigationStrategy) -> None:
        self.strategy = strategy

    def navigate(self) -> None:
        if self.strategy:
            self.strategy.calculate_route()
        else:
            print("No navigation strategy selected")


# Client interface
def main():
    navigation = NavigationContext()

    car_navigation = CarNavigation()
    bike_navigation = BikeNavigation()
    walk_navigation = WalkNavigation()

    navigation.set_strategy(car_navigation)
    navigation.navigate()

    navigation.set_strategy(bike_navigation)
    navigation.navigate()

    navigation.set_strategy(walk_navigation)
    navigation.navigate()


if __name__ == "__main__":
    main()
