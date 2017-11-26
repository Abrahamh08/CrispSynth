//
// Created by cilan on 1/18/2017.
//

#include "crispsynth/resources/LocalResources.h"
#include "crispsynth/mesh/StaticMesh.h"
#include "crispsynth/mesh/BonedMesh.h"
#include <boost/algorithm/string.hpp>

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

// https://stackoverflow.com/a/236803
template<typename Out>
inline void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

inline std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

BoxCollection LocalResources::loadBoxes(std::string group, std::string id) {
    // load box collection and return thing
    BoxCollection returnCollection;
    std::ifstream file;
    file.open((Locator::rootPath / "assets" / group / id).generic_string());
    if (!file) {
        std::cerr << "Unable to open " << id << std::endl;
    }

    std::vector<std::string> tokens;
    std::string fileText;

    while (file.peek() != EOF) {
        std::string token;
        std::getline(file, token);
        token = token.substr(0, token.find(";"));
        tokens.emplace_back(token);
    }

    file.close();

    int state = 0; // 0 = nothing, 1 = hurtbox, 2 = hitbox
    unsigned int count = 0;
    unsigned int lastId = 0;
    HurtboxComponent modify;
    for (const std::string &token : tokens) {
        if (token == "[ub]") {
            count = 0;
            state = 1;
        } else {
            switch (state) {
                case 1:
                    if (count == 0) {
                        count++;
                        lastId = std::stoi(token.substr(0, token.find(":")));
                    }
                    std::string data = token.substr(token.find(':') + 1);
                    std::vector<std::string> floatStrs = split(data, ',');
                    for (unsigned int i = 0; i < floatStrs.size(); i++) {
                        std::string value = floatStrs.at(i);
                        modify.id = lastId;
                        switch(count + i - 1) {
                            case 0:
                                modify.r = std::stof(value);
                                break;
                            case 1:
                                modify.h = std::stof(value);
                            case 2:
                                modify.x = std::stof(value);
                                break;
                            case 3:
                                modify.y = std::stof(value);
                                break;
                            case 4:
                                modify.z = std::stof(value);
                                break;
                            case 5:
                                modify.sX = std::stof(value);
                                break;
                            case 6:
                                modify.sY = std::stof(value);
                                break;
                            case 7:
                                modify.sZ = std::stof(value);
                                break;
                            case 8:
                                boost::trim_left(value);
                                modify.name = value;
                                count = 0;
                                returnCollection.hurtboxes.push_back(modify);
                                break;
                        }
                    }
                    break;
            }
        }
    }

    return returnCollection;
}
