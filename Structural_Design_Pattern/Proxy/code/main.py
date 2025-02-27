from abc import ABC, abstractmethod


# Subject Interface
class Video(ABC):
    @abstractmethod
    def play(self) -> None:
        pass


# Real Subject
class RealVideo(Video):
    def __init__(self, name: str) -> None:
        self.name = name
        self.__load_from_disk()

    def __load_from_disk(self) -> None:
        print(f"Loading Video: {self.name} from disk")

    def play(self) -> None:
        print(f"Playing video: {self.name}", end="\n\n")


# Proxy
class ProxyVideo(Video):
    def __init__(self, filename: str) -> None:
        self.filename: str = filename
        self.real_video = None

    def play(self) -> None:
        if self.real_video is None:
            self.real_video = RealVideo(self.filename)
        self.real_video.play()


def main():
    video1 = ProxyVideo("video1.mp4")
    video2 = ProxyVideo("video2.mp4")

    print("Request to play video1.mp4")
    video1.play()

    print("Request to play video2.mp4")
    video2.play()

    print("Request to play video1.mp4")
    video1.play()


if __name__ == "__main__":
    main()
