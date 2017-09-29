//
// Created by cilan on 6/28/2017.
//

#include "crispsynth/game-objects/StoryObject.h"

StoryObject::StoryObject(std::queue<sf::Texture>& textures) : textures_(textures) {
    putNext();
}

void StoryObject::update() {
    _x = this->getSprite().getPosition().x;
    _y = this->getSprite().getPosition().y;
    width = this->getSprite().getGlobalBounds().width;
    height = this->getSprite().getGlobalBounds().height;
    _sX = this->getSprite().getScale().x;
    _sY = this->getSprite().getScale().y;
}

void StoryObject::update(Game &game, sf::Event &event) {
    if (event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::KeyReleased) {
        textures_.pop();
        putNext();
    }
}

void StoryObject::putNext() {
    if (textures_.empty()) {
        // to do
    } else {
        spriteObj.update(textures_.front());
        this->update();
    }
}

void StoryObject::render(Game &game, float delta) {
    spriteObj.render(game, delta);
}

void StoryObject::updateScale(float scaleX, float scaleY) {
    this->spriteObj.updateScale(scaleX, scaleY);
    this->update();
}

void StoryObject::updatePosition(float tx, float ty) {
    this->spriteObj.updatePosition(tx, ty);
    this->update();
}

sf::Sprite& StoryObject::getSprite() {
    return this->spriteObj.getSprite();
}
