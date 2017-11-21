//
// Created by cilan on 3/18/2017.
//

#ifndef BOXCOLLECTION_H
#define BOXCOLLECTION_H

#include "HitboxObject.h"
#include "components/HurtboxComponent.h"
#include <vector>

class BoxCollection {
public:
    BoxCollection();
    std::vector<HitboxObject> hitboxes = {};
    std::vector<HurtboxComponent> hurtboxes = {};
};

#endif // BOXCOLLECTION_H
