#ifndef CRISPSYNTH_GAME_H
#define CRISPSYNTH_GAME_H

#include "crispsynth/Locator.h"
#include <SFML/Graphics.hpp>

class Scene;

class Game {
public:
    Game(sf::RenderWindow &window);
    Game(sf::RenderWindow &window, bool isView);
    std::shared_ptr<Scene> currentScene;
    std::shared_ptr<Scene> previousScene;
    std::shared_ptr<Scene> transitionScene;
    bool transitioning = false, fullscreen;
    sf::RenderWindow &window;
    void update();
    sf::Time timePerFrame;
    bool view = false;
protected:
    YAML::Node &config = Locator::currentConfig;
};

#endif
