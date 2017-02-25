//
// Created by cilan on 1/18/2017.
//

#include "LocalResources.h"

sf::Texture LocalResources::loadTexture(std::string state, std::string id, sf::IntRect* rect) {
    // load texture and return thing
    std::string path = (Locator::rootPath / "assets" / "images" / state / id).generic_string();

    printf("loading texture named %s\n", id.c_str());

    sf::Texture returnTexture;
    if (rect != 0) {
        returnTexture.loadFromFile(path, *rect);
    } else {
        returnTexture.loadFromFile(path);
    }

    return returnTexture;
}

std::unique_ptr<sf::Music> LocalResources::loadMusic(std::string state, std::string id) {
    // load music and return thing
    std::string path = (Locator::rootPath / "assets" / "audio" / "music" / state / id).generic_string();

    printf("loading music named %s\n", id.c_str());

    std::unique_ptr<sf::Music> returnMusic = std::make_unique<sf::Music>();
    returnMusic -> openFromFile(path);

    return returnMusic;
}

std::unique_ptr<YAML::Node> loadYAML(std::string id) {
    // load YAML Node and return thing
    std::string path = (Locator::rootPath / "assets" / "config" / id).generic_string();

    printf("loading YAML Node named %s\n", id.c_str());
    std::unique_ptr<YAML::Node> returnNode = std::make_unique<YAML::Node>();
    *returnNode = YAML::LoadFile(path);

    return returnNode;
}