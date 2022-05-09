cmake_minimum_required(VERSION 3.20)
project(FlappyBird)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp AnimatedSprite.cpp AnimatedSprite.h Bird.cpp Bird.h Base.cpp Base.h Sky.cpp Sky.h Pipe.cpp Pipe.h Game.cpp Game.h)
add_executable(FlappyBird ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(FlappyBird sfml-window sfml-graphics)