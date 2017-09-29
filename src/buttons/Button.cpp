//
// Created by cilan on 2/25/2017.
//

#include "crispsynth/buttons/Button.h"

Button::Button(std::string text, bool autoSize) {
    this->init(std::move(text), autoSize);
}

Button::Button() {
    this->hasText = false;
}

void Button::setRelativeScale(float mod) {
    spriteObj_.setRelativeScale(mod);
}

void Button::updateScale(float scaleX, float scaleY) {
    spriteObj_.updateScale(scaleX, scaleY);
}

void Button::init(std::string text, bool autoSize) {
    this->autoSize = autoSize;
    this->setLabel(std::move(text));
}

void Button::updateTexture() {
    this->renderTexture.create(this->texture->getSize().x, this->texture->getSize().y);
    this->background.setTexture(*this->texture);
    this->renderTexture.draw(this->background);
    if (this->hasText) {
        this->text.setPosition(this->texture->getSize().x / 2 - this->text.getLocalBounds().width / 2, this->texture->getSize().y / 2 - this->text.getLocalBounds().height / 2);
        this->renderTexture.draw(this->text);
    }
    this->renderTexture.display();
    this->spriteObj_.update(renderTexture.getTexture());
}

void Button::updatePosition(float x, float y) {
    spriteObj_.updatePosition(x, y);
}

void Button::setLabel(std::string text) {
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(autoSize ? (uint16_t) (this->texture->getSize().x / this->text.getCharacterSize() * text.size()) : this->defaultSize);
    this->label = text;
}

void Button::update(Game &game, sf::Event& event) {
    int mx = sf::Mouse::getPosition(game.window).x;
    int my = sf::Mouse::getPosition(game.window).y;
    if (mx < x || my < y || mx > (x + w) || my > (y + h)) {
        if (isHovered) {
            isHovered = false;
            this->sHoverExit();
        }
    } else {
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                this->isPressed = true;
                this->sDownHandler();
                this->downHandler(game);
                break;
            case sf::Event::MouseButtonReleased:
                if (this->isPressed) {
                    this->sClickHandler();
                    this->clickHandler(game);
                }
                else this->sReleaseHandler();
                this->isPressed = false;
                break;
            case sf::Event::MouseMoved:
                this->sHoverHandler(!isHovered);
                this->hoverHandler(game, !isHovered);
                if (!isHovered) isHovered = true;
                break;
            default:
                break;
        }
    }
}

void Button::render(Game &game, float delta) {
    spriteObj_.render(game, delta);
}

const std::string Button::getText() {
    return this->label;
}
