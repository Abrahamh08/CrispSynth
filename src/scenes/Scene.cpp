//
// Created by cilan on 3/15/2017.
//

#include "crispsynth/scenes/Scene.h"
#include "crispsynth/Locator.h"
#include "crispsynth/game-objects/GameObject.h"

Scene::Scene(Game &game) : game(game) {};

void Scene::updateObjects(sf::Event &event) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        const std::shared_ptr<GameObject>& object = gameObjects.at(i);
        object->update(game, event);
    }
}

void Scene::renderObjects(float delta) {
    for (std::shared_ptr<GameObject>& object : gameObjects) {
        object->render(game, delta);
    }
}
