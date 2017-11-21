//
// Created by cilan on 11/07/2017.
//

#ifndef HITBOXOBJECT_H
#define HITBOXOBJECT_H

#include <SFML/Window.hpp>
#include "GameObject.h"
#include "components/HitboxComponent.h"
#include "../Game.h"

class HitboxObject : public GameObject {
public:
    HitboxObject();
    HitboxObject(float x, float y, float z, float sx, float sy, float sz, float h);
    virtual void update(Game &game, sf::Event& event) override {};
    virtual void updatePosition(float x, float y, float z) override;
    void updateRadius(float r);
    void gotoFrame(int n);
    void prevFrame();
    void nextFrame();
    int currentFrame();
private:
    int currentFrame_ = 0;
    std::vector<std::shared_ptr<HitboxComponent>> hitboxFrames_ = {std::make_shared<HitboxComponent>()};
    void updateHitboxFrame();
    float r;
public:
    HitboxComponent *currentHitbox = hitboxFrames_[0].get();
protected:
    std::vector<std::shared_ptr<Component>> components = {hitboxFrames_[currentFrame_]};
};

#endif // HITBOXOBJECT_H
