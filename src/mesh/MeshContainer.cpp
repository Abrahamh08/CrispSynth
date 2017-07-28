#include "mesh/MeshContainer.h"
#include "Locator.h"

MeshContainer::MeshContainer(boost::filesystem::path assetsDir) : assetsDir(assetsDir) {
    // don't do anything
}

bool MeshContainer::has(std::string id) {
    return meshes.find(id) != meshes.end();
}

Mesh* MeshContainer::get(std::string id) {
    return meshes.at(id);
}

StaticMesh* MeshContainer::getStatic(std::string id) {
    return staticMeshes.at(id).get();
}

BonedMesh* MeshContainer::getBoned(std::string id) {
    return bonedMeshes.at(id).get();
}

BonedMesh* MeshContainer::put(std::string id, std::unique_ptr<BonedMesh> mesh) {
    bonedMeshes.emplace(id, std::move(mesh));
    meshes.emplace(id, bonedMeshes.at(id).get());
    return bonedMeshes.at(id).get();
}

BonedMesh* MeshContainer::create(std::string group, std::string id) {
    std::unique_ptr<BonedMesh> tempObject = Locator::getResource()->loadBonedMesh(group, id, textures);
    return put(group + "/" + id, std::move(tempObject));
}

StaticMesh* MeshContainer::put(std::string id, std::unique_ptr<StaticMesh> mesh) {
    staticMeshes.emplace(id, std::move(mesh));
    meshes.emplace(id, staticMeshes.at(id).get());
    return staticMeshes.at(id).get();
}
