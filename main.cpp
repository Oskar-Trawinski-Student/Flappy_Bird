#include <iostream>
#include <vector>
#include "Bird.h"
#include "Pipe.h"
#include "Sky.h"
#include "Base.h"

int bird_frames = 3;
int window_width = 576;
int window_height = 1024;
int pipe_space = 350;
int frames_limit = 30;

int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "FlappyBird (in home)");
    window.setFramerateLimit(frames_limit);
    sf::Clock clock, timer;
    Sky sky(window_width);
    Base base(window_width, window_height);
    Bird bird(bird_frames);
    bird.setBounds(0, window_width,0, window_height);
    std::vector<Pipe> pipes_vector;
    pipes_vector.resize(5);
    for (auto i = 0; i < pipes_vector.size(); ++i) {
        pipes_vector[i].set_space(pipe_space*(i+1));
    }

    //game window things here:
    while (window.isOpen()) {
        sf::Event event;
        sf::Time time = clock.restart();
        sf::Time since_start = timer.getElapsedTime();

        while (window.pollEvent(event)) {
            if (event.type==sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        for (auto &p : pipes_vector) {
            if (p.collision(bird)) {
                bird.endGame(window);
            }
        }
        bird.grawitacja(time, window);
        sky.animate(time, window);
        for (auto &p : pipes_vector) {
            p.animate(time, window);
               if (bird.getPosition().x >= p._sprite_Low.getPosition().x){
                   if (p._counted == false) {
                       bird._points += 1;
                       p._counted = true;
                    }
            }
        }
        base.animate(time, window);
        bird.show_points(window);
        window.draw(bird);
        window.display();
    }
    return 0;
}
