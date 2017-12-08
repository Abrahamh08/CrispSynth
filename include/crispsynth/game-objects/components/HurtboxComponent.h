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
    float x = 0, y = 0, z = 0, sX = 0, sY = 0, sZ = 0, h = 1, r = 5;
    unsigned int id = 0;
    std::string name = "untitled";
};

#endif // HURTBOXCOMPONENT_H
