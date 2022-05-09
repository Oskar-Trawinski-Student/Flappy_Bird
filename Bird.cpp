//
// Created by Oskar Trawiński on 23/02/2022.
//

#include "Bird.h"

Bird :: Bird(int &_frames){
    _skin_color = rand()%3;
    _animation_fps= _frames;
    _points = 0;

    if (_skin_color == 0) {
        _texture.loadFromFile("textures/yellowbird.png");
    }
    if (_skin_color == 1) {
        _texture.loadFromFile("textures/redbird.png");
    }
    if (_skin_color == 2) {
        _texture.loadFromFile("textures/bluebird.png");
    }
    _font.loadFromFile("fonts/pricedown/pricedown_bl.otf");
    _text.setFont(_font);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(25, 15);
    _text.setCharacterSize(50);
    _text.setString("Pkt: " +std::to_string(_points));

    this -> add_animation_frame(sf::IntRect(0, 0, 34, 30)); // 1. frame of animation
    this -> add_animation_frame(sf::IntRect(0, 0, 34, 30)); // 1. frame of animation
    this -> add_animation_frame(sf::IntRect(0, 0, 34, 30)); // 1. frame of animation

    this -> add_animation_frame(sf::IntRect(34, 0, 34, 30)); // 2. frame of animation
    this -> add_animation_frame(sf::IntRect(34, 0, 34, 30)); // 2. frame of animation
    this -> add_animation_frame(sf::IntRect(34, 0, 34, 30)); // 2. frame of animation

    this -> add_animation_frame(sf::IntRect(68, 0, 34, 30)); // 3. frame of animation
    this -> add_animation_frame(sf::IntRect(68, 0, 34, 30)); // 3. frame of animation
    this -> add_animation_frame(sf::IntRect(68, 0, 34, 30)); // 3. frame of animation

    this -> setTextureRect(sf::IntRect(0, 0, 34, 34));
    this -> setPosition(sf::Vector2f(25, 250));
}
void Bird :: grawitacja(sf::Time &_time, sf::RenderWindow &window){
    sf::FloatRect _bird_bounds = getGlobalBounds();
    if (_bird_bounds.top < (_down-60-_bird_bounds.height)) {
        this->move(sf::Vector2f(0, 200*_time.asSeconds()));
        this->setRotation(15);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            this->move(0, 200*_time.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->move(0, -400*_time.asSeconds());
            this->setRotation(-15);
        }
    }
    if (_bird_bounds.top <= _top) {
        this->move(sf::Vector2f(0, 200*_time.asSeconds()));
    }
    if (_bird_bounds.top >= (_down-_bird_bounds.height-120)) {
        endGame(window);
    }
    this->step(_time);
}
void Bird :: show_points(sf::RenderWindow &_window) {
    _text.setString("Pkt: " + std::to_string(_points));
    _window.draw(_text);
}

void Bird :: point_counting(sf::Sprite &_p) {
    if (this->getPosition().x >= _p.getPosition().x){
        this->_points += 1;
    }
}
