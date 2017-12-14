//
// Created by cilan on 11/07/2017
//

#ifndef HITBOXOBJECT_CPP
#define HITBOXOBJECT_CPP

#include "crispsynth/game-objects/HitboxObject.h"

HitboxObject::HitboxObject() {
    // do nothing
}

HitboxObject::HitboxObject(float x, float y, float z, float sx, float sy, float sz, float r) : x(_x), y(_y), z(_z), r(_r) {
    this->updatePosition(x, y, z);
    this->updateRadius(r);
}

void HitboxObject::updatePosition(float x, float y, float z) {
    this->currentHitbox->updatePosition(x, y, z);
    this->_x = this->currentHitbox->x;
    this->_y = this->currentHitbox->y;
    this->_z = this->currentHitbox->z;
}

void HitboxObject::updateX(float x) {
    this->currentHitbox->updateX(x);
    this->_x = this->currentHitbox->x;
}

void HitboxObject::updateY(float y) {
    this->currentHitbox->updateY(y);
    this->_y = this->currentHitbox->y;
}

void HitboxObject::updateZ(float z) {
    this->currentHitbox->updateZ(z);
    this->_z = this->currentHitbox->z;
}

void HitboxObject::updateId(unsigned int id) {
    this->_id = id;
}

unsigned int HitboxObject::currentFrame() {
    return this->currentFrame_;
}

bool HitboxObject::hasFrame(unsigned int frame) {
    return this->hitboxFrames_.find(frame) != this->hitboxFrames_.end();
}

void HitboxObject::updateHitboxFrame() {
    this->currentHitbox = hitboxFrames_.at(this->currentFrame_).get();
    this->_x = this->currentHitbox->x;
    this->_y = this->currentHitbox->y;
    this->_z = this->currentHitbox->z;
}

void HitboxObject::gotoFrame(const unsigned int n) {
    if (this->hitboxFrames_.find(n) == this->hitboxFrames_.end()) {
        this->hitboxFrames_[n] = std::make_shared<HitboxComponent>();
    }
    this->currentFrame_ = n;
    this->updateHitboxFrame();
}

void HitboxObject::nextFrame() {
    this->gotoFrame(currentFrame_ + 1);
}

void HitboxObject::prevFrame() {
    if (currentFrame_ > 0) {
        this->gotoFrame(currentFrame_ - 1);
    }
}

void HitboxObject::updateRadius(float r) {
    this->_r = r;
}

#endif // HITTBOXOBJECT_CPP
