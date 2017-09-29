//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_TEXTOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_TEXTOBJECT_H

#include <SFML/Window.hpp>
#include "GameObject.h"
#include "components/TextComponent.h"
#include "components/DrawableComponent.h"
#include "components/RenderComponent.h"

class TextObject : public GameObject {
public:
    TextObject();
    TextObject(const std::string label, const sf::Font& font);
    virtual void updatePosition(float tx, float ty) override; 
    virtual void update(Game &game, sf::Event& event) override { };
    virtual void render(Game &game, float delta) override;
    void update(const std::string label, const sf::Font& font);
    void updateText(const std::string label);
    void updateScale(const float x, const float y);
    void setCharacterSize(uint16_t size);
    sf::Text& getText();
private:
    std::shared_ptr<TextComponent> text_ = std::make_shared<TextComponent>();
    std::shared_ptr<RenderComponent> render_ = std::make_shared<RenderComponent>();
    std::vector<std::weak_ptr<DrawableComponent>> drawableComponents = {text_};
protected:
    std::vector<std::shared_ptr<Component>> components = {text_, render_};
    virtual void update() override;
};

#endif
