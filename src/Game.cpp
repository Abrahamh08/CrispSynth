#include "crispsynth/Game.h"
#include "crispsynth/scenes/Scene.h"
#include "crispsynth/Locator.h"

Game::Game(sf::RenderWindow &window, bool isView) :  window(window), config(Locator::currentConfig) {
    this->view = isView;
    if (!this->view) {
        this->fullscreen = config["video"]["fullscreen"].as<bool>();
        update();
    }
}

Game::Game(sf::RenderWindow &window) : window(window), config(Locator::currentConfig) {
    if (!this->view) {
        this->fullscreen = config["video"]["fullscreen"].as<bool>();
        update();
    }
}

void Game::update() {
    window.create(sf::VideoMode(config["video"]["width"].as<uint16_t>(),
                config["video"]["height"].as<uint16_t>()),
            config["video"]["title"].as<std::string>(),
            this->fullscreen ? sf::Style::Fullscreen : sf::Style::Close);
    window.setFramerateLimit(Locator::currentConfig["video"]["fps"].as<unsigned int>());
}
