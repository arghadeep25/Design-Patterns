from abc import ABC, abstractmethod


# Base Interface
class FileComponentSystem(ABC):
    @abstractmethod
    def show_details(self) -> None:
        pass


# Leaf: Represent a single file
class File(FileComponentSystem):
    def __init__(self, filename: str) -> None:
        self.filename: str = filename

    def show_details(self) -> None:
        print(f"File Name: {self.filename}")


# Composite: Represent a folder
class Folder(FileComponentSystem):
    def __init__(self, foldername: str) -> None:
        self.foldername: str = foldername
        self.files = []

    def add(self, file: FileComponentSystem) -> None:
        self.files.append(file)

    def show_details(self) -> None:
        print(f"Folder Name: {self.foldername}")
        for file in self.files:
            file.show_details()


# Client Interface
def main() -> None:
    file1 = File("document.txt")
    file2 = File("image.png")

    folder1 = Folder("home")
    folder1.add(file1)
    folder1.add(file2)

    # folder1.show_details()

    folder2 = Folder("temp")
    file3 = File("music.mp3")

    folder2.add(file3)
    folder1.add(folder2)
    folder1.show_details()


if __name__ == "__main__":
    main()
