//
// Created by sauvau_m on 3/21/17.
//

#include <iostream>
#include "../include/Menu.hpp"

arcade::Menu::~Menu() {

}

arcade::Menu::Menu() {}

arcade::Menu::Menu(std::vector<std::string> gamesPath, std::vector<std::string> gfxPath)
        : gamesPath(gamesPath),
          gfxPath(gfxPath), indexGame(0), indexLib(0) {
    for (size_t i = 0; i < gamesPath.size(); ++i) {
        UIComponent *component = new UIComponent(10, 50 * i, 40, 100);
        component->setText(gamesPath[i]);
        components.push_back(component);
		component->setSelected(i == 0);
    }
    for (size_t i = 0; i < gfxPath.size(); ++i) {
        UIComponent *component = new UIComponent(400, 50 * i, 40, 100);
        component->setText(gfxPath[i]);
        components.push_back(component);
		component->setSelected(i == 0);
    }
    updateComponents();
}

void arcade::Menu::moveMenu(int menu, size_t component) {
    if (!menu) {
        components[indexGame]->toogle();
        indexGame = component;
        components[component]->toogle();
    } else {
        components[indexLib + gamesPath.size()]->toogle();
        indexLib = component;
        components[component + gamesPath.size()]->toogle();
    }
    updateComponents();
}

void arcade::Menu::updateComponents() {
    for (size_t i = 0; i < components.size(); ++i) {
        if (components[i]->isSelected())
            components[i]->setTextColor(Color::Red);
        else
            components[i]->setTextColor(Color::White);
    }
}


