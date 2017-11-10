//
// Created by cilan on 11/07/2017.
//

#ifndef HURTBOXOBJECT_H
#define HURTBOXOBJECT_H

#include <SFML/Window.hpp>
#include "GameObject.h"
#include "components/HurtboxComponent.h"
#include "../Game.h"

class HurtboxObject : public GameObject {
public:
    HurtboxObject();
    HurtboxObject(float x, float y, float z, float sx, float sy, float sz);
    HurtboxObject(const sf::Texture& texture);
    virtual void updatePosition(float x, float y, float z) override;
    void updateScale(float x, float y, float z);
    void gotoFrame(int n);
    void prevFrame();
    void nextFrame();
    int currentFrame();
    HurtboxComponent *currentHurtbox = nullptr;
private:
    int currentFrame_ = 0;
    std::vector<std::shared_ptr<HurtboxComponent>> hurtboxFrames_ = {std::make_shared<HurtboxComponent>()};
    void updateHurtboxFrame();
protected:
    std::vector<std::shared_ptr<Component>> components = {hurtboxFrames_[currentFrame_]};
};

#endif // HURTBOXOBJECT_H
