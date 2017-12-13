//
// Created by cilan on 11/07/2017.
//

#ifndef HITBOXOBJECT_H
#define HITBOXOBJECT_H

#include <SFML/Window.hpp>
#include "GameObject.h"
#include "components/HitboxComponent.h"

class Game;

class HitboxObject {
public:
    HitboxObject();
    HitboxObject(float x, float y, float z, float sx, float sy, float sz, float h);
    virtual void updatePosition(float x, float y, float z);
    void updateRadius(float r);
    void gotoFrame(const unsigned int n);
    void prevFrame();
    void nextFrame();
    int currentFrame();
private:
    int currentFrame_ = 0;
    std::map<unsigned int, std::shared_ptr<HitboxComponent>> hitboxFrames_;
    void updateHitboxFrame();
    float _x, _y, _z, _r;
public:
    float &x = _x, &y = _y, &z = _z, &r = _r;
public:
    HitboxComponent *currentHitbox;
};

#endif // HITBOXOBJECT_H
