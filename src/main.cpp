#include "include/config.h"
#include "../include/pong.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "VERSION: " << APP_VERSION << endl;

    Pong* p = new Pong();
    p->init();

    p->eventLoop();


    delete p;

    // sf::Window window(sf::VideoMode(800, 600), "Pong");
    // sf::Event event;

    // window.setVerticalSyncEnabled(true);

    // while (window.isOpen()) {
        
    //     while (window.pollEvent(event)) {
    //         switch(event.type) {
    //             case sf::Event::Closed:
    //                 window.close();
    //                 break;
    //             default:
    //                 ;
    //         }
    //     }
        


    //     window.display();
    // }

    return 0;
}
