//
// Created by Oskar Trawiński on 24/02/2022.
//

#ifndef FLAPPYBIRD_SKY_H
#define FLAPPYBIRD_SKY_H

#include <SFML/Graphics.hpp>

class Sky {
public:
    Sky();
    Sky(int &_x);
    void animate(sf::Time &_time, sf::RenderWindow &window);
    std::vector<sf::Sprite> _vector;

protected:
    int _choice;
    sf::Texture _texture;
};


#endif //FLAPPYBIRD_SKY_H
