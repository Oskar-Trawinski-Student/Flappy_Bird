//
// Created by Oskar Trawiński on 24/02/2022.
//

#include "Sky.h"

Sky :: Sky(int &_x) {
    srand(time(NULL));
    _choice = rand()%2;
    _vector.resize(3);

    if (_choice == 0) {
        _texture.loadFromFile("textures/background-day.png");
    }
    if (_choice == 1) {
        _texture.loadFromFile("textures/background-night.png");
    }
    for (int i = 0; i < 3; ++i) {
        _vector[i].setTexture(_texture);
        _vector[i].setPosition(_x*i, 0);
        _vector[i].setScale(2, 2);
    }
}
void Sky::animate(sf::Time &_time, sf::RenderWindow &window) {
    for (int i = 0; i < 3; ++i) {
        _vector[i].move(-3, 0);

        if (_vector[i].getPosition().x <= -576) {
            _vector[i].setPosition(576, 0);
        }
    }
    for (auto &el : _vector) {
        window.draw(el);
    }
}