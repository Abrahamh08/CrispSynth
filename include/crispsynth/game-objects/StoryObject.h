//
// Created by cilan on 6/28/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_STORYOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_STORYOBJECT_H

#include "SpriteObject.h"
#include <queue>

class StoryObject : public GameObject {
public:
    StoryObject(std::queue<sf::Texture>& textures);
    virtual void update(Game &game, sf::Event& event) override;
    virtual void render(Game &game, float delta) override;
    virtual void update() override;
    virtual void updatePosition(float tx, float ty) override;
    void updateScale(float scaleX, float scaleY);
    sf::Sprite& getSprite();
private:
    SpriteObject spriteObj = SpriteObject();
    std::queue<sf::Texture>& textures_;
    void putNext();
};

#endif
