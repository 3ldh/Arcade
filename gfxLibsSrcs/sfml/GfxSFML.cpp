//
// Created by sauvau_m on 3/17/17.
//

#include <SFML/Window.hpp>
#include <iostream>
#include "GfxSFML.hpp"

bool arcade::GfxSFML::pollEvent(arcade::Event &e) {
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

}

void arcade::GfxSFML::updateMap(const arcade::IMap &map) {

}

void arcade::GfxSFML::updateGUI(const arcade::IGUI &gui) {

}

void arcade::GfxSFML::display() {
    std::cout << "display yolo" << std::endl;
}

void arcade::GfxSFML::clear() {

}

arcade::GfxSFML::~GfxSFML() {

}

arcade::GfxSFML::GfxSFML() {}

void arcade::GfxSFML::openWindow() {
    sf::Window window(sf::VideoMode(800, 600), "My window");
}

extern "C" arcade::GfxSFML *getClone()
{
    return new arcade::GfxSFML();
}