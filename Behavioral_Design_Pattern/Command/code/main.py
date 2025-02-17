from abc import ABC, abstractmethod
from typing import List


# Receiver
class Light:
    def turn_on(self) -> None:
        print("Light turned on")

    def turn_off(self) -> None:
        print("Light turned off")


# Common Interface
class Command(ABC):
    @abstractmethod
    def execute(self) -> None:
        pass


# Concrete Command: turn on
class TurnOn(Command):
    def __init__(self, light: Light) -> None:
        self.light: Light = light

    def execute(self) -> None:
        self.light.turn_on()


# Concrete Command: turn off
class TurnOff(Command):
    def __init__(self, light: Light) -> None:
        self.light: Light = light

    def execute(self) -> None:
        self.light.turn_off()


# Invoker
class RemoteControl:
    def __init__(self) -> None:
        self.commands: List[Command] = []

    def set_commands(self, command: Command) -> None:
        self.commands.append(command)

    def press_button(self) -> None:
        for command in self.commands:
            command.execute()
            self.commands.remove(command)


# Client
def main() -> None:
    light = Light()
    turn_on_command = TurnOn(light=light)
    turn_off_command = TurnOff(light=light)

    remote_control = RemoteControl()
    remote_control.set_commands(turn_on_command)
    print("Turning on the lights")
    remote_control.press_button()

    print("Turning off the lights")
    remote_control.set_commands(turn_off_command)
    remote_control.press_button()
    

if __name__ == "__main__":
    main()