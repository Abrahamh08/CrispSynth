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
    void updateX(float x);
    void updateY(float y);
    void updateZ(float z);
    void updateFrame(uint16_t transitionFrame);
    float x = 0, y = 0, z = 0;
    unsigned int id = 0;
};

#endif // HITBOXCOMPONENT_H
