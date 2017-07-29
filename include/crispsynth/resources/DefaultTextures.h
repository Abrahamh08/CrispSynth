//
// Created by cilan on 7/29/2017.
//

#ifndef CRISPSYNTH_DEFAULTTEXTURES_H
#define CRISPSYNTH_DEFAULTTEXTURES_H

#include <SFML/Graphics/Texture.hpp>
#include <crispsynth/Locator.h>
#include <crispsynth/resources/TextureLoader.h>

class DefaultTextures {
public:
    static void init();
    static sf::Font defaultFont;
    static sf::Font typeFont;
};

#endif
