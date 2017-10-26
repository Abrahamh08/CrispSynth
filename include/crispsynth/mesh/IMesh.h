//
// Created by cilan on 7/12/2017
//

#ifndef IMESH_H
#define IMESH_H

#include <assimp/scene.h>
#include <boost/filesystem.hpp>
#include <string>
#include <map>
#include "Texture.h"

class Mesh
{
public:
    virtual bool loadFromFile(boost::filesystem::path path, std::map<std::string, Texture>& textures) = 0;
    virtual bool initFromScene(const aiScene* pScene) = 0;
    virtual void draw() = 0;
    std::map<std::string, Texture>* textures;
protected:
    boost::filesystem::path path;
};

#endif
