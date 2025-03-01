#include "audio_player/audio_player.h"

#include <stdexcept>

AudioPlayer::AudioPlayer() : state(State::OFF) {}

void AudioPlayer::PowerOnOrOff() {
  if (state == AudioPlayerInterface::State::OFF)
    state = AudioPlayerInterface::State::STOPPED;
  else
    state = AudioPlayerInterface::State::OFF;
}
void AudioPlayer::PlayOrPause() {
  if (state != AudioPlayerInterface::State::OFF) {
    if (state == AudioPlayerInterface::State::PLAYING)
      state = AudioPlayerInterface::State::PAUSED;
    else
      // In both STOPPED and PAUSED states, start playing
      state = AudioPlayerInterface::State::PLAYING;
  } else
    throw std::runtime_error("Cannot play audio while OFF");
}
void AudioPlayer::Stop() {
  if (state != AudioPlayerInterface::State::OFF)
    state = AudioPlayerInterface::State::STOPPED;
  else
    throw std::runtime_error("Cannot stop audio while OFF");
}
AudioPlayerInterface::State AudioPlayer::GetState() { return state; }
