#include <iostream>
#include <memory>

// Forward Declaration
class MusicPlayerState;

// Context Class
class MusicPlayer {
 private:
  std::shared_ptr<MusicPlayerState> state;

 public:
  void set_state(const std::shared_ptr<MusicPlayerState> &new_state);
  void press_play();
  void press_stop();
  void press_pause();
};

// State Interface
class MusicPlayerState {
 public:
  virtual ~MusicPlayerState() = default;
  virtual void press_play(MusicPlayer &) = 0;
  virtual void press_stop(MusicPlayer &) = 0;
  virtual void press_pause(MusicPlayer &) = 0;
};

// Concrete State: Playing
class PlayingState : public MusicPlayerState {
 public:
  void press_play(MusicPlayer &) override {
    std::cout << "Already playing music." << std::endl;
  }

  void press_stop(MusicPlayer &) override;
  void press_pause(MusicPlayer &player) override;
};

// Concrete State: Paused
class PausedState : public MusicPlayerState {
 public:
  void press_play(MusicPlayer &) override;
  void press_stop(MusicPlayer &) override;
  void press_pause(MusicPlayer &) override {
    std::cout << "Music is already paused." << std::endl;
  }
};

// Concrete State: Stopped
class StoppedState : public MusicPlayerState {
 public:
  void press_play(MusicPlayer &) override;

  void press_stop(MusicPlayer &) override {
    std::cout << "Music is already stopped." << std::endl;
  }
  void press_pause(MusicPlayer &) override {
    std::cout << "Can't pause. Music is already stopped." << std::endl;
  }
};

// State transitions
void PlayingState::press_pause(MusicPlayer &player) {
  std::cout << "Pausing Music..." << std::endl;
  player.set_state(std::make_shared<PausedState>());
}

void PlayingState::press_stop(MusicPlayer &player) {
  std::cout << "Stopping Music..." << std::endl;
  player.set_state(std::make_shared<StoppedState>());
}

void PausedState::press_play(MusicPlayer &player) {
  std::cout << "Resuming Music..." << std::endl;
  player.set_state(std::make_shared<PlayingState>());
}

void PausedState::press_stop(MusicPlayer &player) {
  std::cout << "Stopping Music from Pause..." << std::endl;
  player.set_state(std::make_shared<StoppedState>());
}

void StoppedState::press_play(MusicPlayer &player) {
  std::cout << "Starting Music..." << std::endl;
  player.set_state(std::make_shared<PlayingState>());
}

void MusicPlayer::set_state(
    const std::shared_ptr<MusicPlayerState> &new_state) {
  this->state = new_state;
}

// Context Method Implementation
void MusicPlayer::press_play() { this->state->press_play(*this); }

void MusicPlayer::press_pause() { this->state->press_pause(*this); }

void MusicPlayer::press_stop() { this->state->press_stop(*this); }

// Client Side
int main() {
  MusicPlayer player;
  player.set_state(std::make_shared<StoppedState>());

  player.press_play();
  player.press_pause();
  player.press_play();
  player.press_stop();
}