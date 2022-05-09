//
// Created by Oskar Trawiński on 23/02/2022.
//

#include "Base.h"

Base :: Base(int &_x, int &_y) {
    _vector.resize(3);
     _texture.loadFromFile("textures/base.png");

    for (int i = 0; i < 3; ++i) {
        _vector[i].setTexture(_texture);
        _vector[i].setPosition(_x*i, (_y-150));
        _vector[i].setScale(2, 2);
    }
}
void Base :: animate(sf::Time &_time, sf::RenderWindow &window) {
    for (int i = 0; i < 3; ++i) {
        _vector[i].move(-150*_time.asSeconds(), 0);

        if (_vector[i].getPosition().x <= -576) {
            _vector[i].setPosition(2*576, 874);
        }
    }
    for (auto &el : _vector) {
        window.draw(el);
    }
}