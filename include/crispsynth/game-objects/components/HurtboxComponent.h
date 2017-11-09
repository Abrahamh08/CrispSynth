//
// Created by cilan on 11/07/2017.
//

#ifndef HURTBOXCOMPONENT_H
#define HURTBOXCOMPONENT_H

#include "Component.h"

class HurtboxComponent : public Component {
public:
    HurtboxComponent();

    using Component::update;
    void updatePosition(float x, float y, float z);
    void updateScale(float x, float y, float z);
    void updateFrame(uint16_t transitionFrame);
    float x, y, z, sX, sY, sZ;
};

#endif // HURTBOXCOMPONENT_H
