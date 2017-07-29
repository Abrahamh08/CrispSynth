//
// Created by cilan on 1/20/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LOCALRESOURCES_H
#define I_AM_SYNTHETIC_C_SFML_LOCALRESOURCES_H

#include "IResources.h"
#include "../Locator.h"

class LocalResources : public IResources {
public:
    virtual sf::Texture loadTexture(std::string state, std::string id, sf::IntRect*) override;
    virtual std::unique_ptr<BonedMesh> loadBonedMesh(std::string group, std::string id, std::map<std::string, Texture>& textures) override;
    virtual std::unique_ptr<StaticMesh> loadStaticMesh(std::string group, std::string id, std::map<std::string, Texture>& textures) override;
    virtual std::unique_ptr<sf::Music> loadMusic(std::string state, std::string id) override;
    virtual std::string loadPath(std::string id) override;
    virtual sf::Font loadFont(std::string id) override;
    virtual sf::Image loadImage(std::string state, std::string id) override;
};

#endif
