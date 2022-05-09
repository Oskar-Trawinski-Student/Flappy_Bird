//
// Created by Oskar Trawiński on 16/03/2022.
//

#include "Game.h"

Game::Game(int &x, int &y, int &fps) {
    _window_width=x;
    _window_height=y;
    _frames_limit=fps;
    _size.x=_window_width;
    _size.y-_window_height;

    _window.setFramerateLimit(_frames_limit);
    _window.setSize(_size);
    _window.setTitle("My Game");
}
