cmake_minimum_required(VERSION 3.10)

project(programming_paradigms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(AudioPlayer
    src/audio_player.cpp)

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} AudioPlayer)

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  -Wshadow
  -Wnon-virtual-dtor
  -Wcast-align -Wunused
  -Woverloaded-virtual
  -Wconversion
  -Wsign-conversion
  -Wduplicated-cond
  -Wnull-dereference
  -Wuseless-cast
  -Wdouble-promotion
  -Wformat=2
  -pedantic)
