#ifndef PONG_HPP
#define PONG_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define GAME_TITLE "Pong"

class Pong {


private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::Vector2i mousePosition;

    sf::CircleShape* shape;

    void processEvents();
    void updateState();
    void render();

public:
    Pong();
    virtual ~Pong();

    void init();
    void eventLoop();

};


#endif /* PONG_HPP */
