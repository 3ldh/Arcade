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

const arcade::IComponent &arcade::GUI::at(std::size_t n) const {
    return *components.at(n);
}

std::vector<arcade::IComponent *>::const_iterator arcade::GUI::begin() const {
    return components.begin();
}

std::vector<arcade::IComponent *>::const_iterator arcade::GUI::end() const {
    return components.end();
}

void arcade::GUI::addComponent(arcade::IComponent *component) {
    components.push_back(component);
}

