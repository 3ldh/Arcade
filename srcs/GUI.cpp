//
// Created by sauvau_m on 3/18/17.
//

#include "../include/GUI.hpp"

arcade::GUI::~GUI() {

}

arcade::GUI::GUI() {}

size_t arcade::GUI::size() const {
    return components.size();
}

void arcade::GUI::addComponent(arcade::UIComponent *component) {
    components.push_back(component);
}

arcade::IComponent &arcade::GUI::at(std::size_t n) {
    return *components[n];
}

void arcade::GUI::updateComponents() {

}

