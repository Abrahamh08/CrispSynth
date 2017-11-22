//
// Created by cilan on 11/20/2017.
//

#ifndef HURTBOXCOMPONENT_H
#define HURTBOXCOMPONENT_H

#include "Component.h"

class HurtboxComponent {
public:
    HurtboxComponent();

    void updatePosition(float x, float y, float z);
    void updateScale(float sX, float sY);
    void updateHeight(float h);
    void updateRadius(float r);
    void updateFrame(uint16_t transitionFrame);
    float x, y, z, sX, sY, sZ, h, r;
};

#endif // HURTBOXCOMPONENT_H
