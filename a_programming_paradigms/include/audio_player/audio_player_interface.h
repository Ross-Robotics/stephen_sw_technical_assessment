#pragma once
#include <memory>
#include <string>

class AudioPlayerInterface {
 public:
  using Ptr = std::shared_ptr<AudioPlayerInterface>;

  enum class State { OFF, STOPPED, PAUSED, PLAYING };

  virtual ~AudioPlayerInterface() {}
  virtual void PowerOnOrOff() = 0;
  virtual void PlayOrPause() = 0;
  virtual void Stop() = 0;
  virtual State GetState() = 0;

  static std::string StateToStr(State state) {
    if (state == State::OFF) return "OFF";
    if (state == State::STOPPED) return "STOPPED";
    if (state == State::PAUSED) return "PAUSED";
    if (state == State::PLAYING) return "PLAYING";
    return "UNKNOWN";
  }
};