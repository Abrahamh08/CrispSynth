//
// Created by cilan on 11/07/2017
//

#ifndef HITTBOXOBJECT_CPP
#define HITBOXOBJECT_CPP

#include "crispsynth/game-objects/HitboxObject.h"

HitboxObject::HitboxObject() {
    // do nothing
}

HitboxObject::HitboxObject(float x, float y, float z, float sx, float sy, float sz, float h) {
    this->updatePosition(x, y, z);
    this->updateHeight(h);
}

void HitboxObject::updatePosition(float x, float y, float z) {
    this->currentHitbox->updatePosition(x, y, z);
    this->_x = this->currentHitbox->x;
    this->_y = this->currentHitbox->y;
    this->_z = this->currentHitbox->z;
}

void HitboxObject::updateHeight(float h) {
    this->currentHitbox->updateHeight(h);
    this->height = this->currentHitbox->h;
}

int HitboxObject::currentFrame() {
    return this->currentFrame_;
}

void HitboxObject::updateHitboxFrame() {
    this->currentHitbox = hitboxFrames_[this->currentFrame_].get();
    this->_x = this->currentHitbox->x;
    this->_y = this->currentHitbox->y;
    this->_z = this->currentHitbox->z;
    this->height = this->currentHitbox->h;
}

void HitboxObject::gotoFrame(int n) {
    if (!this->hitboxFrames_[n]) {
        this->hitboxFrames_[n] = std::make_shared<HitboxComponent>();
    }
    this->currentFrame_ = n;
    this->updateHitboxFrame();
}

void HitboxObject::nextFrame() {
    this->currentFrame_++;
    if ((unsigned) this->currentFrame_ >= this->hitboxFrames_.size()) {
        this->hitboxFrames_.emplace_back(std::make_shared<HitboxComponent>());
    }
    this->updateHitboxFrame();
}

void HitboxObject::prevFrame() {
    if (currentFrame_ > 0) {
        this->currentFrame_--;
        this->updateHitboxFrame();
    }
}

#endif // HITTBOXOBJECT_CPP
