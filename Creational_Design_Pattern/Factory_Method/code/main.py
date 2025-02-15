from abc import ABC, abstractmethod


# Abstract transportation class
class Transport(ABC):
    def __init__(self) -> None:
        pass

    @abstractmethod
    def deliver(self) -> None:
        pass


# Concrete transportation: Truck
class Truck(Transport):
    def deliver(self) -> None:
        print(f"Delivering by land in a truck")


# Concrete transportation: Truck
class Plane(Transport):
    def deliver(self) -> None:
        print(f"Delivering by air in a plane")


# Concrete transportation: Ship
class Ship(Transport):
    def deliver(self) -> None:
        print(f"Delivering by water in a ship")
        

# Abstract logistics class
class Logistics(ABC):
    @abstractmethod
    def plan_delivery(self) -> None:
        pass


# Concrete logistics: Road
class RoadLogistics(Logistics):
    def plan_delivery(self) -> Truck:
        return Truck()


# Concrete logistics: Air
class AirLogistics(Logistics):
    def plan_delivery(self) -> Plane:
        return Plane()

# Concrete logistics: Water
class WaterLogistics(Logistics):
    def plan_delivery(self) -> Plane:
        return Ship()


def main() -> None:

    road_logistics = RoadLogistics()
    transport: Truck = road_logistics.plan_delivery()
    transport.deliver()

    air_logistics = AirLogistics()
    transport: Plane = air_logistics.plan_delivery()
    transport.deliver()
    
    water_logistics = WaterLogistics()
    transport: Ship = water_logistics.plan_delivery()
    transport.deliver()


if __name__ == "__main__":
    main()
