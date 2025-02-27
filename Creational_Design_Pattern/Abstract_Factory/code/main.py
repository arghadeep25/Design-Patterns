from abc import ABC, abstractmethod

# Abstract Products


class SmartSpeaker(ABC):
    @abstractmethod
    def play_music(self) -> None:
        pass


class SmartLight(ABC):
    @abstractmethod
    def turn_on(self) -> None:
        pass


# Concrete Products for Amazon Devices


class EchoSpeaker(SmartSpeaker):
    def play_music(self) -> str:
        return "Playing music on Echo Speaker"


class AlexaLight(SmartLight):
    def turn_on(self) -> str:
        return "Turning on Alexa light"


# Concrete Products for Google Devices
class NestSpeaker(SmartSpeaker):
    def play_music(self) -> str:
        return "Playing music on Nest Speaker"


class GoogleLight(SmartLight):
    def turn_on(self) -> str:
        return "Turning on Google light"


# Abstract Factory
class SmartHomeFactory(ABC):
    @abstractmethod
    def create_speaker(self) -> None:
        pass

    @abstractmethod
    def create_light(self) -> None:
        pass


# Concrete Factory for Google Devices


class GoogleDeviceFactory(SmartHomeFactory):
    def create_speaker(self) -> NestSpeaker:
        return NestSpeaker()

    def create_light(self) -> GoogleLight:
        return GoogleLight()


# Concrete Factory for Amazon Devices


class AlexaDeviceFactory(SmartHomeFactory):
    def create_speaker(self) -> EchoSpeaker:
        return EchoSpeaker()

    def create_light(self) -> AlexaLight:
        return AlexaLight()


# Client Code
def use_smart_home(factory: SmartHomeFactory) -> None:
    speaker = factory.create_speaker()
    light = factory.create_light()
    print(speaker.play_music())
    print(light.turn_on())


def main():
    print("Testing Google Speaker and Light")
    use_smart_home(GoogleDeviceFactory())

    print("Testing Alexa Speaker and Light")
    use_smart_home(AlexaDeviceFactory())


if __name__ == "__main__":
    main()
