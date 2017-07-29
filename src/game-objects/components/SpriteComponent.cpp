//
// Created by cilan on 5/24/2017.
//

#include "crispsynth/game-objects/components/SpriteComponent.h"

SpriteComponent::SpriteComponent() {
    // do nothing
}

void SpriteComponent::update(const sf::Texture& texture) {
    sprite.setTexture(texture);
}

void SpriteComponent::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
