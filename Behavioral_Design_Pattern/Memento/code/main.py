from typing import List

# Memento: stores the state
class Memento:
    def __init__(self, state: str) -> None:
        self.state: str = state

    def get_state(self) -> str:
        return self.state


# Originator
class TextEditor:
    def __init__(self) -> None:
        self.__text: str = ""

    def type(self, words: str) -> None:
        self.__text += words + " "

    def show(self) -> None:
        print(f"Editor Content: {self.__text}")

    def save(self) -> Memento:
        return Memento(self.__text)

    def restore(self, memento: Memento) -> None:
        self.__text = memento.get_state()


# Caretaker: manages history of memento
class History:
    def __init__(self) -> None:
        self.__history: List[Memento] = []

    def add_history(self, memento: Memento) -> None:
        self.__history.append(memento)

    def get_history(self, index: int) -> Memento:
        return self.__history[index]


# Client code 
def main() -> None:
    editor = TextEditor()
    history = History()

    editor.type("hello")
    history.add_history(editor.save())

    editor.type("world")
    history.add_history(editor.save())
    
    editor.show()
    editor.restore(history.get_history(0))
    editor.show()


if __name__ == "__main__":
    main()
