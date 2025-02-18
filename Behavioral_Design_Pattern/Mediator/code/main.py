from abc import ABC, abstractmethod
from typing import List


# Mediator Interface
class ChatMediator(ABC):
    @abstractmethod
    def add_user(self, user: "User") -> None:
        pass

    @abstractmethod
    def send_message(self, message: str, sender: "User") -> None:
        pass


# Concrete User
class User:
    def __init__(self, mediator: ChatMediator, name: str) -> None:
        self.mediator: ChatMediator = mediator
        self.name: str = name

    def send(self, message: str) -> None:
        print(f"{self.name} sends: {message}")
        self.mediator.send_message(message, self)

    def receive(self, message: str, sender_name: str) -> None:
        print(f"{self.name} received from {sender_name}: {message}")


# Concrete Mediator
class ChatRoom(ChatMediator):
    def __init__(self) -> None:
        self.users: List[User] = []

    def add_user(self, user: User) -> None:
        self.users.append(user)

    def send_message(self, message: str, sender: User) -> None:
        for user in self.users:
            if user is not sender:
                user.receive(message, sender.name)


def main() -> None:
    chat_room = ChatRoom()

    alice = User(chat_room, "Alice")
    bob = User(chat_room, "Bob")
    charlie = User(chat_room, "Charlie")

    chat_room.add_user(alice)
    chat_room.add_user(bob)
    chat_room.add_user(charlie)

    print()
    alice.send("Hello everyone!")
    print()
    bob.send("Hello Alice!")

if __name__ == "__main__":
    main()
