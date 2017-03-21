//
// Created by sauvau_m on 3/17/17.
//

#include <SFML/Window.hpp>
#include <iostream>
#include "GfxSFML.hpp"

arcade::GfxSFML::~GfxSFML() {

}

arcade::GfxSFML::GfxSFML() {
    initializeWindow();

    inputsKeyboard[sf::Keyboard::Key::Escape]
            = createArcadeEvent(arcade::ActionType::AT_PRESSED, arcade::KeyboardKey::KB_ESCAPE);
    inputsKeyboard[sf::Keyboard::Key::Up]
            = createArcadeEvent(arcade::ActionType::AT_PRESSED, arcade::KeyboardKey::KB_ARROW_UP);
    inputsKeyboard[sf::Keyboard::Key::Down]
            = createArcadeEvent(arcade::ActionType::AT_PRESSED, arcade::KeyboardKey::KB_ARROW_DOWN);
    inputsKeyboard[sf::Keyboard::Key::Left]
            = createArcadeEvent(arcade::ActionType::AT_PRESSED, arcade::KeyboardKey::KB_ARROW_LEFT);
    inputsKeyboard[sf::Keyboard::Key::Right]
            = createArcadeEvent(arcade::ActionType::AT_PRESSED, arcade::KeyboardKey::KB_ARROW_RIGHT);
}


bool arcade::GfxSFML::pollEvent(arcade::Event &e) {

    sf::Event eventSFML;
    while (window.pollEvent(eventSFML)) {
        if (eventSFML.type == sf::Event::Closed) {
            e = inputsKeyboard[sf::Keyboard::Key::Escape];
            window.close();
            return true;
        }
        if (eventSFML.type == sf::Event::KeyPressed) {
            auto it = inputsKeyboard.find(eventSFML.key.code);
            if (it != inputsKeyboard.end()) {
                e = (*it).second;
                return true;
            }
        }
    }
    return false;
}

bool arcade::GfxSFML::doesSupportSound() const {
    return false;
}

void arcade::GfxSFML::loadSounds(std::vector<std::string> const &sounds) {

}

void arcade::GfxSFML::playSound(int soundId) {

}

void arcade::GfxSFML::setSize(size_t height, size_t width) {

}

void arcade::GfxSFML::setPosition(size_t y, size_t x) {

}

void arcade::GfxSFML::initializeWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Arcade - SFML", sf::Style::Close | sf::Style::Titlebar,
                  settings);
    window.setMouseCursorVisible(false);
}

void arcade::GfxSFML::updateMap(const arcade::IMap &map) {
    for (size_t i = 0; i < map.getLayerNb(); ++i) {
        for (size_t j = 0; j < map.getHeight(); ++j) {
            for (size_t k = 0; k < map.getWidth(); ++k) {
                arcade::Color c = map[i][j][k]->getColor();
                if (map[i][j][k]->getTypeEv() == TileTypeEvolution::PLAYER) {
                    sf::CircleShape circle(WIN_WIDTH / map.getWidth() / 2);
                    circle.setFillColor(sf::Color(c.rgba[0], c.rgba[1], c.rgba[2]));
                    circle.setPosition(WIN_WIDTH / map.getWidth() * k, WIN_HEIGHT / map.getHeight() * j);
                    window.draw(circle);
                } else {
                    sf::RectangleShape rectangle(
                            sf::Vector2f(WIN_WIDTH / map.getWidth(), WIN_HEIGHT / map.getHeight()));
                    rectangle.setPosition(WIN_WIDTH / map.getWidth() * k, WIN_HEIGHT / map.getHeight() * j);
                    rectangle.setFillColor(sf::Color(c.rgba[0], c.rgba[1], c.rgba[2]));
                    rectangle.setOutlineColor(sf::Color(sf::Color::Black));
                    rectangle.setOutlineThickness(1);
                    window.draw(rectangle);
                }
            }
        }
    }
}

void arcade::GfxSFML::updateGUI(const arcade::IGUI &gui) {

}

void arcade::GfxSFML::display() {
    window.display();
}

void arcade::GfxSFML::clear() {
    window.clear();
}

sf::Event arcade::GfxSFML::createSFMLEvent(sf::Event::EventType et, sf::Keyboard::Key keyCode) {
    sf::Event event;

    event.type = et;
    event.key.code = keyCode;
    return event;
}

arcade::Event arcade::GfxSFML::createArcadeEvent(arcade::ActionType at, arcade::KeyboardKey keyCode) {
    arcade::Event event;

    event.type = arcade::EventType::ET_KEYBOARD;
    event.action = at;
    event.kb_key = keyCode;
    return event;
}


extern "C" arcade::GfxSFML *getClone() {
    return new arcade::GfxSFML();
}