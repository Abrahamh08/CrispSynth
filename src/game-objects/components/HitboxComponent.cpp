//
// Created by cilan on 11/07/2017
//

#ifndef HITBOXCOMPONENT_CPP
#define HITBOXCOMPONENT_CPP

#include "crispsynth/game-objects/components/HitboxComponent.h"

HitboxComponent::HitboxComponent() {
    // do nothing
}

void HitboxComponent::updatePosition(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void HitboxComponent::updateHeight(float h) {
    this->h = h;
}

#endif // HITBOXCOMPONENT_CPP
