from abc import ABC, abstractmethod

# Defining the product
class House:
    def __init__(self) -> None:
        self.walls = None
        self.roof = None
        self.doors = None
        self.windows = None

    def set_walls(self, walls: str) -> None:
        self.walls: str = walls

    def set_roof(self, roof: str) -> None:
        self.roof: str = roof

    def set_doors(self, doors: str) -> None:
        self.doors: str = doors

    def set_windows(self, windows: str) -> None:
        self.windows: str = windows

    def show(self) -> None:
        print(f"House Details::", end=" ")
        print(f"Walls: {self.walls}", end=", ")
        print(f"Roof: {self.roof}", end=", ")
        print(f"Doors: {self.doors}", end=", ")
        print(f"Windows: {self.windows}")

# Defining abstract builder
class HouseBuilder(ABC):
    @abstractmethod
    def build_walls(self) -> None:
        pass

    @abstractmethod
    def build_roof(self) -> None:
        pass

    @abstractmethod
    def build_doors(self) -> None:
        pass

    @abstractmethod
    def build_windows(self) -> None:
        pass

    @abstractmethod
    def get_house(self) -> None:
        pass


# Defining concrete builder: Wooden House 
class WoodenHouseBuilder(HouseBuilder):
    def __init__(self) -> None:
        self.house = House()

    def build_walls(self) -> None:
        self.house.set_walls("Wooden walls")

    def build_roof(self) -> None:
        self.house.set_roof("Wooden roof")

    def build_doors(self) -> None:
        self.house.set_doors("Wooden doors")

    def build_windows(self) -> None:
        self.house.set_windows("Wooden windows")

    def get_house(self) -> House:
        return self.house

# Defining concrete builder: Stone House 
class StoneHouseBuilder(HouseBuilder):
    def __init__(self) -> None:
        self.house = House()

    def build_walls(self) -> None:
        self.house.set_walls("Stone walls")

    def build_roof(self) -> None:
        self.house.set_roof("Stone roof")

    def build_doors(self) -> None:
        self.house.set_doors("Stone doors")

    def build_windows(self) -> None:
        self.house.set_windows("Stone windows")

    def get_house(self) -> House:
        return self.house


# Defining construction director
class ConstructionDirector:
    def __init__(self, builder: HouseBuilder) -> None:
        self.house_builder: HouseBuilder = builder

    def build_house(self) -> None:
        self.house_builder.build_walls()
        self.house_builder.build_roof
        self.house_builder.build_doors()
        self.house_builder.build_windows()

# Client code
def main():
    wooden_builder = WoodenHouseBuilder()
    construction_director = ConstructionDirector(wooden_builder)
    construction_director.build_house()
    wooden_house: House = wooden_builder.get_house()
    wooden_house.show()

    stone_builder = StoneHouseBuilder()
    construction_director = ConstructionDirector(stone_builder)
    construction_director.build_house()
    stone_house: House = stone_builder.get_house()
    stone_house.show()


if __name__ == "__main__":
    main()
