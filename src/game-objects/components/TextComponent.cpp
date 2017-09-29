//
// Created by cilan on 5/24/2017.
//

#include "crispsynth/game-objects/components/TextComponent.h"

TextComponent::TextComponent() {
    // do nothing
}

void TextComponent::update(const std::string label, const sf::Font& font) {
    text.setFont(font);
    text.setString(label);
}

void TextComponent::update(const std::string label) {
    text.setString(label);
}

void TextComponent::draw(Game &game) {
    game.window.draw(text);
}
