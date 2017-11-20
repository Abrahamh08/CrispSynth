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
    void updateHeight(float h);
    void updateFrame(uint16_t transitionFrame);
    float x, y, z, sX, sY, sZ, h;
};

#endif // HITBOXCOMPONENT_H
