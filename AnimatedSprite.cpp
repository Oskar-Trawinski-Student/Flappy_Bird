#include "AnimatedSprite.h"

AnimatedSprite :: AnimatedSprite(){
    srand(time(NULL));
    _actual_frame = 0;

    this -> setTexture(_texture);
    this -> setPosition(sf::Vector2f(0, 0));
    this->setScale(2 ,2);
}
void AnimatedSprite :: add_animation_frame(const sf::IntRect &_rect) {
    _animation_frames.emplace_back(_rect);
}
void AnimatedSprite :: step(const sf::Time &czas) {
    setTextureRect(_animation_frames[_actual_frame]);

    if (_actual_frame >= _animation_frames.size() - 1) {
        _actual_frame = 0;
    } else {
        _actual_frame ++;
    }
}
void AnimatedSprite :: setBounds(int left, int right, int top, int down) {
    _top = top;
    _down = down;
    _left = left;
    _right = right;
}
void AnimatedSprite :: endGame(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    sf::sleep(sf::seconds(3));
    window.close();
}