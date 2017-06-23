//
// Created by cilan on 4/8/2017.
//

#include "ConfirmButton.h"

bool ConfirmFilenameButton::clickHandler(sf::RenderWindow& window) {
    std::cout << "click handler invoked" << std::endl;
    clicked = true;
    return false;
}

bool ConfirmFilenameButton::wasClicked() {
    return this->clicked;
}
