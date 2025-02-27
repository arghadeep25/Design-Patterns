from abc import ABC, abstractmethod


# Forward Declaration
class MusicPlayerState(ABC):
    pass


# Context Class
class MusicPlayer:
    def __init__(self) -> None:
        self.state: MusicPlayerState = None

    def set_state(self, new_state: MusicPlayerState) -> None:
        self.state = new_state

    def press_play(self) -> None:
        self.state.press_play(self)

    def press_stop(self) -> None:
        self.state.press_stop(self)

    def press_pause(self) -> None:
        self.state.press_pause(self)


# State Interface
class MusicPlayerState(ABC):
    @abstractmethod
    def press_play(self, music_player: MusicPlayer) -> None:
        pass

    @abstractmethod
    def press_stop(self, music_player: MusicPlayer) -> None:
        pass

    @abstractmethod
    def press_pause(self, music_player: MusicPlayer) -> None:
        pass


# Concrete State: Playing
class PlayingState(MusicPlayerState):
    def press_play(self, music_player: MusicPlayer) -> None:
        print("Already playing music")

    def press_stop(self, music_player: MusicPlayer) -> None:
        print("Stopping Music")
        music_player.set_state(StoppedState())

    def press_pause(self, music_player: MusicPlayer) -> None:
        print("Pausing music")
        music_player.set_state(PausedState())


# Concrete State: Pause
class PausedState(MusicPlayerState):
    def press_play(self, music_player: MusicPlayer) -> None:
        print("Resuming Music")
        music_player.set_state(PlayingState())

    def press_stop(self, music_player: MusicPlayer) -> None:
        print("Stopping Music")
        music_player.set_state(StoppedState())

    def press_pause(self, music_player: MusicPlayer) -> None:
        print("Music is already paused")


# Concrete State: Stop
class StoppedState(MusicPlayerState):
    def press_play(self, music_player: MusicPlayer) -> None:
        print("Playing Music")
        music_player.set_state(PlayingState())

    def press_stop(self, music_player: MusicPlayer) -> None:
        print("Music is already stopped")

    def press_pause(self, music_player: MusicPlayer) -> None:
        print("Can't pause!! Music is already stopped")


# Client Interface
def main() -> None:
    player = MusicPlayer()
    player.set_state(StoppedState())

    player.press_play()
    player.press_pause()
    player.press_stop()


if __name__ == "__main__":
    main()
