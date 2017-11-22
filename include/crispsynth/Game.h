#ifndef CRISPSYNTH_GAME_H
#define CRISPSYNTH_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <yaml-cpp/yaml.h>

class Scene;
class Locator;

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
    YAML::Node &config;
};

#endif
