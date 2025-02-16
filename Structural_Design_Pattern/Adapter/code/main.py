from abc import ABC, abstractmethod
import os

# Target Interface: Old Media Player
class MediaPlayer(ABC):
    def play(self) -> None:
        pass


# Adaptee: Advanced Media Player
class AdvancedMediaPlayer(ABC):
    @abstractmethod
    def play_mp4(self, filename: str) -> None:
        pass

    @abstractmethod
    def play_vlc(self, filename: str) -> None:
        pass

# Concrete Prototype: MP4 player
class Mp4Player(AdvancedMediaPlayer):
    def play_mp4(self, filename: str) -> None:
        print(f"Playing MP4 file:: {filename}")
    
    def play_vlc(self,filename:str) -> None:
        pass

# Concrete Prototype: VLC player
class VLCPlayer(AdvancedMediaPlayer):
    def play_mp4(self, filename:str) -> None:
        pass
    
    def play_vlc(self, filename: str) -> None:
        print(f"Playing VLC fie:: {filename}")


# Adapter: Plugging Media Player and Advanced Media Player
class MediaAdapter(MediaPlayer):
    def __init__(self, media_type: str) -> None:
        self.advanced_player = None
        self.media_type = media_type
        if self.media_type == "vlc":
            self.advanced_player = VLCPlayer()
        elif self.media_type == "mp4":
            self.advanced_player = Mp4Player()
        else:
            raise NameError("Wrong file type selected")

    def play(self, filename: str) -> None:
        if self.media_type == "mp4":
            self.advanced_player.play_mp4(filename=filename)
        elif self.media_type == "vlc":
            self.advanced_player.play_vlc(filename=filename)

# Client Interface
class Player(MediaPlayer):
    def __init__(self) -> None:
        super().__init__()
        
    def play(self, filename: str) -> None:
        file_extension: str = filename.split(".")[1]
        if file_extension == "mp3":
            print(f"Playing mp3 file:: {filename}")
        elif file_extension == "mp4" or "vlc":
            adapter = MediaAdapter(file_extension)
            adapter.play(filename=filename)
        else:
            raise NameError("Invalid media type")


def main() -> None:
    player = Player()
    player.play("songs.mp3")
    player.play("video.mp4")
    player.play("movie.vlc")
    player.play("binary.so")


if __name__ == "__main__":
    main()
