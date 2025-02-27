from abc import ABC, abstractmethod
from typing import List


# Abstract Observer
class Observer(ABC):
    @abstractmethod
    def update(self, temperature: float) -> None:
        pass


# Subject Interface
class Subject(ABC):
    @abstractmethod
    def attach(self, observer: Observer) -> None:
        pass

    @abstractmethod
    def detach(self, observer: Observer) -> None:
        pass

    @abstractmethod
    def notify(self) -> None:
        pass


# Concrete Subject
class WeatherStation(Subject):
    def __init__(self):
        self.observers: List[Observer] = []
        self.temperature: float = 0.0

    def set_temperature(self, temperature: float) -> None:
        self.temperature = temperature
        self.notify()

    def attach(self, observer: Observer) -> None:
        self.observers.append(observer)

    def detach(self, observer) -> None:
        self.observers.remove(observer)

    def notify(self) -> None:
        for observer in self.observers:
            observer.update(self.temperature)


# Concrete Observer: Laptop
class Laptop(Observer):
    def update(self, temperature: float) -> None:
        print(f"Laptop: {temperature}")


# Concrete Observer: Phone
class Phone(Observer):
    def update(self, temperature: float) -> None:
        print(f"Phone: {temperature}")


# Client side
def main() -> None:
    weather_station = WeatherStation()
    phone = Phone()
    laptop = Laptop()

    weather_station.attach(phone)
    weather_station.attach(laptop)

    weather_station.set_temperature(23.6)
    weather_station.set_temperature(29.4)

    weather_station.detach(phone)
    weather_station.set_temperature(27.4)


if __name__ == "__main__":
    main()
