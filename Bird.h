//
// Created by Oskar Trawiński on 23/02/2022.
//

#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H

#include "AnimatedSprite.h"
#include "Pipe.h"

class Bird : public AnimatedSprite {
public:
    Bird(int &_frames);
    void grawitacja(sf::Time &_time, sf::RenderWindow &window);
    void show_points(sf::RenderWindow &_window);
    void point_counting(sf::Sprite &_p);
protected:
    int _skin_color;
};


#endif //FLAPPYBIRD_BIRD_H
