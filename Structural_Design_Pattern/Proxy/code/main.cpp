#include <iostream>
#include <memory>
#include <unordered_map>

// Subject Interface
class Video {
 public:
  virtual ~Video() = default;
  virtual void play() const = 0;
};

// Real Subject
class RealVideo : public Video {
 private:
  std::string name;
  void load_from_disk() const {
    std::cout << "Loading video: " << this->name << " from disk" << std::endl;
  }

 public:
  explicit RealVideo(const std::string &file) : name(std::move(file)) {
    this->load_from_disk();
  }

  void play() const override {
    std::cout << "Playing Video: " << this->name << std::endl << std::endl;
  }
};

// Proxy: control access to RealVideo
class ProxyVideo : public Video {
 private:
  std::string filename;
  // const function can't modify any member variable
  // in order to do that we need to use the mutable
  // if we remove the mutable the keyword the compiler
  // will immediately throw error
  mutable std::shared_ptr<RealVideo> real_video_ptr;

 public:
  explicit ProxyVideo(const std::string &filename)
      : filename(std::move(filename)) {}

  void play() const override {
    if (!real_video_ptr) {
      real_video_ptr = std::make_shared<RealVideo>(filename);
    }
    real_video_ptr->play();
  }
};

int main() {
  std::shared_ptr<Video> video1 = std::make_shared<ProxyVideo>("video1.mp4");
  std::shared_ptr<Video> video2 = std::make_shared<ProxyVideo>("video2.mp4");

  std::cout << "Request to play video1.mp4" << std::endl;
  video1->play();

  std::cout << "Request to play video2.mp4" << std::endl;
  video2->play();

  std::cout << "Request to play video1.mp4" << std::endl;
  video1->play();
}