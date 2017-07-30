//
// Created by cilan on 1/18/2017.
//

#include "crispsynth/resources/LocalResources.h"
#include "crispsynth/mesh/StaticMesh.h"
#include "crispsynth/mesh/BonedMesh.h"

sf::Texture LocalResources::loadTexture(std::string state, std::string id, sf::IntRect* rect) {
    // load texture and return thing
    std::string path = (Locator::rootPath / "assets" / "images" / state / id).generic_string();

    std::cout << "loading texture named " << id.c_str() << std::endl;

    sf::Texture returnTexture;
    if (rect != nullptr) {
        returnTexture.loadFromFile(path, *rect);
    } else {
        returnTexture.loadFromFile(path);
    }

    return returnTexture;
}

std::unique_ptr<BonedMesh> LocalResources::loadBonedMesh(std::string group, std::string id, std::map<std::string, Texture>& textures) {
    // load boned mesh and return thing
    boost::filesystem::path path = Locator::rootPath / "assets" / "meshes" / group / id;

    std::cout << "loading boned mesh named " << id.c_str() << std::endl;

    std::unique_ptr<BonedMesh> mesh = std::make_unique<BonedMesh>();
    mesh->loadFromFile(path, textures);

    return mesh;
}

std::unique_ptr<StaticMesh> LocalResources::loadStaticMesh(std::string group, std::string id, std::map<std::string, Texture>& textures) {
    // load static mesh and return thing
    boost::filesystem::path path = Locator::rootPath / "assets" / "meshes" / group / id;

    std::cout << "loading static mesh named " << id.c_str() << std::endl;

    std::unique_ptr<StaticMesh> mesh = std::make_unique<StaticMesh>();
    mesh->loadFromFile(path, textures);

    return mesh;
}

std::unique_ptr<sf::Music> LocalResources::loadMusic(std::string state, std::string id) {
    // load music and return thing
    std::string path = (Locator::rootPath / "assets" / "audio" / "music" / state / id).generic_string();

    std::cout << "loading music named " << id.c_str() << std::endl;

    std::unique_ptr<sf::Music> returnMusic = std::make_unique<sf::Music>();
    returnMusic->openFromFile(path);

    return returnMusic;
}

std::string LocalResources::loadPath(std::string id) {
    // returns path
    std::string path = (Locator::rootPath / "assets" / "config" / id).generic_string();

    std::cout << "loading path of file named " << id.c_str() << std::endl;

    return path;
}

sf::Font LocalResources::loadFont(std::string id) {
    // load font and return thing
    std::string path = (Locator::rootPath / "assets" / "fonts" / id).generic_string();
    sf::Font font;
    font.loadFromFile(path);

    std::cout << "loading font named \n" << id.c_str() << std::endl;

    return font;
}

sf::Image LocalResources::loadImage(std::string state, std::string id) {
    // load image and return thing
    std::string path = (Locator::rootPath / "assets" / "images" / state / id).generic_string();

    std::cout << "loading image named " << id.c_str() << std::endl;

    sf::Image returnImage;
    returnImage.loadFromFile(path);

    return returnImage;
}
