#include <iostream>

#include "audio_player/audio_player.h"

AudioPlayerInterface::Ptr player;

void DisplayMenu() {
  std::cout << "Media Player controls: " << std::endl
            << "p : Pause/Play" << std::endl
            << "s : Stop" << std::endl
            << "o : Power On/Off" << std::endl
            << "q : Quit" << std::endl;
}
void DisplayState() {
  if (player) {
    AudioPlayerInterface::State state = player->GetState();
    std::cout << "The state of the audio player is "
              << AudioPlayerInterface::StateToStr(state) << std::endl;
  }
}

int main() {
  player = std::make_shared<AudioPlayer>();

  DisplayMenu();
  DisplayState();

  char input;
  while (input != 'q') {
    std::cout << std::endl << "Input Command: ";
    std::cin >> input;
    try {
      switch (input) {
        case 'p':
          player->PlayOrPause();
          break;
        case 's':
          player->Stop();
          break;
        case 'o':
          player->PowerOnOrOff();
          break;
        case 'q':
          break;
        default:
          std::cout << "Unknown command" << std::endl;
      }
    } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << '\n';
    }
    DisplayState();
  }

  return 0;
}
