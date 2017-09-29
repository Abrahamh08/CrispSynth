//
// Created by cilan on 5/24/2017.
//

#include "crispsynth/game-objects/components/RectangleComponent.h"

RectangleComponent::RectangleComponent() {
    // do nothing
}

void RectangleComponent::update(const sf::Texture* texture) {
    this->shape.setTexture(texture);
}

void RectangleComponent::draw(Game &game) {
    game.window.draw(shape);
}
