//
// Created by cilan on 5/24/2017.
//

#include "crispsynth/game-objects/components/ShapeComponent.h"

ShapeComponent::ShapeComponent() {
    // do nothing
}

void ShapeComponent::update(sf::Shape& shape) {
    this->shape = &shape;
}

void ShapeComponent::draw(Game &game) {
    game.window.draw(*shape);
}
