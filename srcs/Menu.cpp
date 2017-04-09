//
// Created by sauvau_m on 3/21/17.
//

#include <iostream>
#include "../include/Menu.hpp"

arcade::Menu::~Menu() {

}

arcade::Menu::Menu() {}

arcade::Menu::Menu(std::vector<std::string> gamesPath, std::vector<std::string> gfxPath, size_t indexLib)
        : gamesPath(gamesPath),
          gfxPath(gfxPath), indexGame(0), indexLib(indexLib) {
    for (size_t i = 0; i < gamesPath.size(); ++i) {
        UIComponent *component = new UIComponent(0.01, 0.05 * i, 0.04, 0.12);
        component->setText(gamesPath[i]);
        components.push_back(component);
		component->setSelected(i == 0);
    }

    for (size_t i = 0; i < gfxPath.size(); ++i) {
        UIComponent *component = new UIComponent(0.5, 0.05 * i, 0.04, 0.12);
        component->setText(gfxPath[i]);
        components.push_back(component);
		component->setSelected(i == indexLib);
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


