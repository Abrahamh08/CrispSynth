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
    void updateX(float x);
    void updateY(float y);
    void updateZ(float z);
    void updateRadius(float r);
    void updateId(unsigned int id);
    void updateName(std::string &id);
    void gotoFrame(const unsigned int n);
    void prevFrame();
    void nextFrame();
    bool hasFrame(unsigned int frame);
    unsigned int currentFrame();
private:
    unsigned int currentFrame_ = 0;
    std::map<unsigned int, std::shared_ptr<HitboxComponent>> hitboxFrames_;
    void updateHitboxFrame();
    float _x, _y, _z, _r;
    unsigned int _id;
    std::string _name;
public:
    float x() const { return _x; }
    float y() const { return _y; }
    float z() const { return _z; }
    float r() const { return _r; }
    std::string name() const { return _name; }
    unsigned int id() const { return _id; }
public:
    HitboxComponent *currentHitbox;
};

#endif // HITBOXOBJECT_H
