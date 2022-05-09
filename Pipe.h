//
// Created by Oskar Trawiński on 24/02/2022.
//

#ifndef FLAPPYBIRD_PIPE_H
#define FLAPPYBIRD_PIPE_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include "Bird.h"

class Pipe {
public:
    Pipe();
    void move(sf::Time &_time);
    void set_space(int _x);
    void animate(sf::Time &_time, sf::RenderWindow &window);
    bool collision(sf::Sprite &_b);
    int _pos_y;
    int _pos_x;
    sf::Sprite _sprite_Low, _sprite_Up;
    bool _counted;

private:
  sf::Texture _texture;
  int _choice;
  int _gap_size;
  int _width;
  friend class Bird;
};


#endif //FLAPPYBIRD_PIPE_H
