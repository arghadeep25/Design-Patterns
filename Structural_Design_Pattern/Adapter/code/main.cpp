#include <iostream>
#include <memory>

// Target interface
class MediaPlayer {
 public:
  virtual ~MediaPlayer() = default;
  virtual void play(const std::string &) const = 0;
};

// Adaptee: Advanced Media Player
class AdvancedMediaPlayer {
 public:
  virtual ~AdvancedMediaPlayer() = default;
  virtual void playMp4(const std::string &) const = 0;
  virtual void playVLC(const std::string &) const = 0;
};

class Mp4Player : public AdvancedMediaPlayer {
 public:
  void playMp4(const std::string &filename) const override {
    std::cout << "Playing MP4 file:: " << filename << std::endl;
  }

  void playVLC(const std::string &) const override {}
};

class VLCPlayer : public AdvancedMediaPlayer {
 public:
  void playMp4(const std::string &) const override {}
  void playVLC(const std::string &filename) const override {
    std::cout << "Playing VLC file:: " << filename << std::endl;
  }
};

// Adapter : Converts Advanced Media Player to Media Player
class MediaAdapter : public MediaPlayer {
 public:
  explicit MediaAdapter(const std::string &mediaType) : mediaType(mediaType) {
    // advancedPlayer = (mediaType == "mp4") ? std::make_shared<Mp4Player>()
    //                                     : std::make_shared<VLCPlayer>();
    if (mediaType == "mp4")
      advancedPlayer = std::make_shared<Mp4Player>();
    else if (mediaType == "vlc")
      advancedPlayer = std::make_shared<VLCPlayer>();
  }

 public:
  void play(const std::string &filename) const override {
    if (mediaType == "mp4")
      advancedPlayer->playMp4(filename);
    else if (mediaType == "vlc")
      advancedPlayer->playVLC(filename);
  }

 private:
  std::string mediaType;
  std::shared_ptr<AdvancedMediaPlayer> advancedPlayer;
};

// Client Audio Player
class AudioPlayer : public MediaPlayer {
 public:
  void play(const std::string &filename) const override {
    std::string fileExtension = filename.substr(filename.find_last_of('.') + 1);

    if (fileExtension == "mp3") {
      std::cout << "Playing MP3 file: " << filename << std::endl;
    } else if (fileExtension == "mp4" || fileExtension == "vlc") {
      MediaAdapter adapter(fileExtension);
      adapter.play(filename);
    } else {
      std::cout << "Invalid media type: " << filename << std::endl;
    }
  }
};

int main() {
  AudioPlayer player;
  player.play("song.mp3");
  player.play("video.mp4");
  player.play("movie.vlc");
  player.play("binary.so");
}