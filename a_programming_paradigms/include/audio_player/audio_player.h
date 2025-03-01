#pragma once
#include <memory>

#include "audio_player/audio_player_interface.h"

class AudioPlayer : public AudioPlayerInterface {
 public:
  using Ptr = std::shared_ptr<AudioPlayerInterface>;

  AudioPlayer();
  virtual void PowerOnOrOff();
  virtual void PlayOrPause();
  virtual void Stop();
  virtual AudioPlayerInterface::State GetState();

 private:
  State state;
};