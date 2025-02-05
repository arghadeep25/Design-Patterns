#include <iostream>
#include <memory>

class VideoDecoder {
 public:
  void decode() { std::cout << "Decoding video..." << std::endl; }
};

class AudioProcessor {
 public:
  void process() { std::cout << "Processing audio..." << std::endl; }
};

class SubtitleLoader {
 public:
  void load() { std::cout << "Loading subtitle..." << std::endl; }
};

class DRMChecker {
 public:
  void check() { std::cout << "Checking DRM..." << std::endl; }
};

// Facade
class MoviePlayer {
 private:
  std::shared_ptr<VideoDecoder> video_decoder_ptr;
  std::shared_ptr<AudioProcessor> audio_processor_ptr;
  std::shared_ptr<SubtitleLoader> sub_loader_ptr;
  std::shared_ptr<DRMChecker> drm_checker_ptr;

 public:
  MoviePlayer()
      : video_decoder_ptr(std::make_shared<VideoDecoder>()),
        audio_processor_ptr(std::make_shared<AudioProcessor>()),
        sub_loader_ptr(std::make_shared<SubtitleLoader>()),
        drm_checker_ptr(std::make_shared<DRMChecker>()) {}

 public:
  void play() {
    video_decoder_ptr->decode();
    audio_processor_ptr->process();
    sub_loader_ptr->load();
    drm_checker_ptr->check();
    std::cout << "Playing Movie..." << std::endl;
  }
};

int main() {
  std::shared_ptr<MoviePlayer> movie_player = std::make_shared<MoviePlayer>();
  std::cout << "Client trying to play a movie" << std::endl;
  movie_player->play();
}