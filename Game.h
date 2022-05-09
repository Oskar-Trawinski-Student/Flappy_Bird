//
// Created by Oskar Trawiński on 16/03/2022.
//

#ifndef FLAPPYBIRD_GAME_H
#define FLAPPYBIRD_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
public:
    Game(int &x, int &y, int &fps);

private:
    sf::RenderWindow _window;
    sf::Vector2u _size;
    int _window_width;
    int _window_height;
    int _frames_limit;
};


#endif //FLAPPYBIRD_GAME_H
