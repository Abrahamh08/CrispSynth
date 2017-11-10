//
// Created by cilan on 11/07/2017
//

#ifndef HURTBOXOBJECT_CPP
#define HURTBOXOBJECT_CPP

#include "crispsynth/game-objects/HurtboxObject.h"

HurtboxObject::HurtboxObject() {
    // do nothing
}

HurtboxObject::HurtboxObject(float x, float y, float z, float sx, float sy, float sz) {
    // do something
}

void HurtboxObject::updatePosition(float x, float y, float z) {
    this->currentHurtbox->updatePosition(x, y, z);
    this->_x = this->currentHurtbox->x;
    this->_y = this->currentHurtbox->y;
    this->_z = this->currentHurtbox->z;
}

void HurtboxObject::updateScale(float x, float y, float z) {
    this->currentHurtbox->updateScale(x, y, z);
    this->_sX = this->currentHurtbox->sX;
    this->_sY = this->currentHurtbox->sY;
    this->_sZ = this->currentHurtbox->sZ;
}

int HurtboxObject::currentFrame() {
    return this->currentFrame_;
}

void HurtboxObject::updateHurtboxFrame() {
    this->currentFrame_ = this->hurtboxFrames_.size() - 1;
    this->currentHurtbox = hurtboxFrames_[currentFrame_].get();
    this->_sX = this->currentHurtbox->sX;
    this->_sY = this->currentHurtbox->sY;
    this->_sZ = this->currentHurtbox->sZ;
    this->_x = this->currentHurtbox->x;
    this->_y = this->currentHurtbox->y;
    this->_z = this->currentHurtbox->z;
}

void HurtboxObject::gotoFrame(int n) {
    if (!this->hurtboxFrames_.at(n)) {
        this->hurtboxFrames_[n] = std::make_shared<HurtboxComponent>();
    }
    this->currentFrame_ = n;
    this->updateHurtboxFrame();
}

void HurtboxObject::nextFrame() {
    int n = this->currentFrame_ + 1;
    if (!this->hurtboxFrames_.at(n)) {
        this->hurtboxFrames_[n] = std::make_shared<HurtboxComponent>();
    }

    if ((unsigned) currentFrame_ == this->hurtboxFrames_.size() - 1) {
        this->currentFrame_ = 0;
    } else {
        this->currentFrame_++;
    }
    this->updateHurtboxFrame();
}

void HurtboxObject::prevFrame() {
    if (currentFrame_ <= 0) {
        this->currentFrame_ = this->hurtboxFrames_.size() - 1;
    }

    if (!this->hurtboxFrames_[this->currentFrame_]) {
        this->hurtboxFrames_[this->currentFrame_] = std::make_shared<HurtboxComponent>();
    }
    this->updateHurtboxFrame();
}

#endif // HURTBOXOBJECT_CPP
