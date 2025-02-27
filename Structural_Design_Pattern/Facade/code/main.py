# Internal Process: Video decoder
class VideoDecoder:
    def decode(self) -> None:
        print("Decoding Video...")


# Internal Process: audio processor
class AudioProcessor:
    def process(self) -> None:
        print("Processing audio...")


# Internal Process: subtitle loader
class SubtitleLoader:
    def load(self) -> None:
        print("Loading subtitles...")


# Internal Process: drm checker
class DRMChecker:
    def check(self) -> None:
        print("Checking DRM...")


# User interface
class MoviePlayer:
    def __init__(self) -> None:
        self.video_decoder: VideoDecoder = VideoDecoder()
        self.audio_processor: AudioProcessor = AudioProcessor()
        self.subtitle_loader: SubtitleLoader = SubtitleLoader()
        self.drm_checker: DRMChecker = DRMChecker()

    def play(self):
        self.video_decoder.decode()
        self.audio_processor.process()
        self.subtitle_loader.load()
        self.drm_checker.check()
        print("Playing movie...")


# Client code
def main() -> None:
    movie_player = MoviePlayer()
    movie_player.play()


if __name__ == "__main__":
    main()
