//
// Created by Abraham Hamidi on 3/9/17.
//

#include "CreditsButton.h"

void CreditsButton::clickHandler(sf::RenderWindow& window) {
    window.clear();
    window.display();
    sf::Event event;
    while (window.isOpen()) {
        window.waitEvent(event);
    }
}