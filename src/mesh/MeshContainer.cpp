#include "crispsynth/mesh/MeshContainer.h"
#include "crispsynth/Locator.h"

MeshContainer::MeshContainer() {
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

BonedMesh* MeshContainer::createBoned(std::string group, std::string id) {
    std::unique_ptr<BonedMesh> tempObject = Locator::getResource()->loadBonedMesh(group, id, textures);
    return put((boost::filesystem::path(group) / id).string(), std::move(tempObject));
}

StaticMesh* MeshContainer::createStatic(std::string group, std::string id) {
    std::unique_ptr<StaticMesh> tempObject = Locator::getResource()->loadStaticMesh(group, id, textures);
    return put((boost::filesystem::path(group) / id).string(), std::move(tempObject));
}

StaticMesh* MeshContainer::put(std::string id, std::unique_ptr<StaticMesh> mesh) {
    staticMeshes.emplace(id, std::move(mesh));
    meshes.emplace(id, staticMeshes.at(id).get());
    return staticMeshes.at(id).get();
}
