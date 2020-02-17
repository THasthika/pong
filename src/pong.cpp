#include "../include/pong.hpp"

using namespace std;

Pong::Pong() {
    cout << "instantiating game..." << endl;
}

Pong::~Pong() {
    if (window != nullptr) {
        delete window;
    }

    if (shape != nullptr) {
        delete shape;
    }

    cout << "destroying game..." << endl;
}

void Pong::init() {
    cout << "init variables..." << endl;

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);

    mousePosition.x = 0;
    mousePosition.y = 0;

    shape = new sf::CircleShape(50);
    shape->setFillColor(sf::Color::White);
}

void Pong::eventLoop() {
    cout << "starting event loop..." << endl;

    while (window->isOpen()) {
        this->processEvents();
        this->updateState();
        this->render();
    }

    cout << "stopping event loop..." << endl;
}

void Pong::processEvents() {
    while (window->pollEvent(event)) {
        switch (event.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseMoved:
                mousePosition.x = event.mouseMove.x;
                mousePosition.y = event.mouseMove.y;
                break;
            default:
                break;
        }
    }
}

void Pong::updateState() {
    shape->setPosition(mousePosition.x - 50, mousePosition.y - 50);
}

void Pong::render() {
    window->clear(sf::Color::Black);

    window->draw(*shape);

    window->display();
}
