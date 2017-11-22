//
// Created by cilan on 3/21/2017.
//

#ifndef BOXCOLLECTION_H
#define BOXCOLLECTION_H

#include <vector>
#include "../game-objects/HitboxObject.h"
#include "../game-objects/components/HurtboxComponent.h"

class BoxCollection {
public:
    BoxCollection();
    std::vector<HitboxObject> hitboxes;
    std::vector<HurtboxComponent> hurtboxes;
};

#endif // BOXCOLLECTION_H
