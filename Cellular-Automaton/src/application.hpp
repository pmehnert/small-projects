#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "abstract_game.hpp"

const uint WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 1024;
const uint WINDOW_FRAMERATE = 60;
const size_t GRID_DIM_X = 256, GRID_DIM_Y = 256;

class Application
{
public:
    Application(AbstractGame &game);
    int mainloop();

private:
    sf::RenderWindow window;
    AbstractGame &game;

    void pollEvents();
};

#endif  // APPLICATION_HPP_INCLUDED
