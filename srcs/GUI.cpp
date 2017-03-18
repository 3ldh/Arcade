//
// Created by sauvau_m on 3/18/17.
//

#include "../include/GUI.hpp"

arcade::IGUI::~IGUI() {}

arcade::GUI::~GUI() {

}

arcade::GUI::GUI() {}

void arcade::GUI::createComponent(const std::string &name, TypeComponent component) {
    (void)name;
    (void)component;
}


