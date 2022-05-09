//
// Created by Oskar Trawiński on 23/02/2022.
//

#ifndef FLAPPYBIRD_BASE_H
#define FLAPPYBIRD_BASE_H

#include <SFML/Graphics.hpp>
#include "Bird.h"

class Base {
public:
    Base();
    Base(int &_x, int &_y);
    void animate(sf::Time &_time, sf::RenderWindow &window);
    bool collision(Bird &_b);
    std::vector<sf::Sprite> _vector;
protected:
    sf::Texture _texture;
};


#endif //FLAPPYBIRD_BASE_H
