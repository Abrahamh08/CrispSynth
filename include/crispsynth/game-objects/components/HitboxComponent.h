//
// Created by cilan on 11/07/2017.
//

#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

#include "Component.h"

class HitboxComponent : public Component {
public:
    HitboxComponent();

    using Component::update;
    void updatePosition(float x, float y, float z);
    void updateFrame(uint16_t transitionFrame);
    float x, y, z;
};

#endif // HITBOXCOMPONENT_H
