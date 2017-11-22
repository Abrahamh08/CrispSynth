//
// Created by cilan on 11/07/2017
//

#ifndef HURTBOXCOMPONENT_CPP
#define HURTBOXCOMPONENT_CPP

#include "crispsynth/game-objects/components/HurtboxComponent.h"

HurtboxComponent::HurtboxComponent() {
    // do nothing
}

void HurtboxComponent::updatePosition(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void HurtboxComponent::updateScale(float sX, float sY) {
    this->sX = sX;
    this->sY = sY;
}

void HurtboxComponent::updateHeight(float h) {
    this->h = h;
}

void HurtboxComponent::updateRadius(float r) {
    this->r = r;
}

#endif // HURTBOXCOMPONENT_CPP
