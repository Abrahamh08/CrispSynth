//
// Created by cilan on 2/25/2017.
//

#ifndef CRISPSYNTH_BUTTON_H
#define CRISPSYNTH_BUTTON_H

#include <string>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Locator.h"
#include "../game-objects/components/SpriteComponent.h"
#include "../game-objects/components/RenderComponent.h"
#include "../game-objects/GameObject.h"
#include "../game-objects/SpriteObject.h"
#include "../Game.h"

class Button : public GameObject {
public:
    Button();
    Button(std::string text, bool autoSize = false);
    void setLabel(std::string text);
    const std::string getText();
    virtual void update(Game &game, sf::Event& event) override;
    virtual void render(Game &game, float delta) override;
    void setRelativeScale(float mod = .1);
    void updateScale(float scaleX, float scaleY);
    virtual void updatePosition(float x, float y) override;
    void updateTexture();
    virtual ~Button(){}
    sf::Event event;
    sf::Texture* texture;
    bool isPressed = false;
    bool isHovered = false;
    bool hasText = true;
private:
    void init(std::string text, bool autoSize);
    sf::RenderTexture renderTexture;
protected:
    std::string label;
    sf::Text text;
    sf::Font font;
    bool autoSize;
    uint16_t defaultSize;
    sf::Sprite background;

    virtual void sHoverExit(){}
    virtual void sClickHandler(){}
    virtual void sDownHandler(){}
    virtual void sReleaseHandler(){}
    virtual void sHoverHandler(bool first){}

    virtual void clickHandler(Game &game){}
    virtual void downHandler(Game &game){}
    virtual void hoverHandler(Game &game, bool first) {}

    SpriteObject spriteObj_ = SpriteObject();

public:
    float &w = spriteObj_.w,
          &h = spriteObj_.h,
          &x = spriteObj_.x,
          &y = spriteObj_.y,
          &sX = spriteObj_.sX,
          &sY = spriteObj_.sY;
};

#endif
