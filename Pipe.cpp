//
// Created by Oskar Trawiński on 24/02/2022.
//

#include "Pipe.h"

Pipe :: Pipe() {
    srand(time(NULL));
    _pos_x = 350;
    _pos_y = rand()%10*25+100;
    _gap_size = 250;
    _choice = std::rand()%2;
    _counted = false;

    if (_choice == 0) {
        _texture.loadFromFile("textures/pipe-green.png");
    }
    if (_choice == 1) {
        _texture.loadFromFile("textures/pipe-red.png");
    }
    //Upper pipe:
    _sprite_Up.setTexture(_texture);
    _sprite_Up.setPosition(_pos_x, _pos_y);
    _sprite_Up.setScale(2, -2);
    //Lower pipe:
    _sprite_Low.setTexture(_texture);
    _sprite_Low.setPosition(_pos_x, _pos_y+_gap_size);
    _sprite_Low.setScale(2, 2);
    _width = -2*_sprite_Low.getLocalBounds().width;
}
void Pipe :: move(sf::Time &_time) {
    _sprite_Up.move(-150*_time.asSeconds(), 0);
    _sprite_Low.move(-150*_time.asSeconds(), 0);
}
void Pipe :: set_space(int _x) {
    _pos_y = std::rand()%25*10+100;
    _sprite_Up.setPosition(_x, _pos_y);
    _sprite_Low.setPosition(_x, _pos_y+_gap_size);
}
void Pipe :: animate(sf::Time &_time, sf::RenderWindow &window) {
    this->move(_time);
    if (_sprite_Low.getPosition().x <= _width) {
        _pos_y = std::rand()%10*25+100;
        _counted = false;
        _sprite_Up.setPosition(5*_pos_x, _pos_y);
        _sprite_Low.setPosition(5*_pos_x, _pos_y+_gap_size);
    }
    window.draw(_sprite_Up);
    window.draw(_sprite_Low);
}
bool Pipe::collision(sf::Sprite &_b) {
    if ((_b.getGlobalBounds().intersects(_sprite_Low.getGlobalBounds())) || (_b.getGlobalBounds().intersects(_sprite_Up.getGlobalBounds() ))) {
        return true;
    }
    return false;
}
