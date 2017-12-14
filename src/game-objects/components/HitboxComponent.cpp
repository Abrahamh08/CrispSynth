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

void HitboxComponent::updateX(float x) {
    this->x = x;
}

void HitboxComponent::updateY(float y) {
    this->y = y;
}

void HitboxComponent::updateZ(float z) {
    this->z = z;
}

#endif // HITBOXCOMPONENT_CPP
