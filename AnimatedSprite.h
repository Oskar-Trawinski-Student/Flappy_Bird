//
// Created by Oskar Trawiński on 23/02/2022.
//

#ifndef FLAPPYBIRD_ANIMATEDSPRITE_H
#define FLAPPYBIRD_ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite();
    void add_animation_frame(const sf::IntRect &_rect);
    void step(const sf::Time &_time);
    void setBounds(int left, int right, int top, int down);
    void endGame(sf::RenderWindow &window);
    int _points;

protected:
    int _animation_fps;
    int _actual_frame;
    int _top;
    int _down;
    int _left;
    int _right;

    sf::Texture _texture;
    sf::Text _text;
    sf::Font _font;
    std::vector <sf::IntRect> _animation_frames;
};


#endif //FLAPPYBIRD_ANIMATEDSPRITE_H
