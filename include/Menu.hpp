//
// Created by sauvau_m on 3/21/17.
//

#ifndef CPP_ARCADE_MENU_HPP
#define CPP_ARCADE_MENU_HPP

#include "GUI.hpp"

namespace arcade {
    class Menu : public GUI {
        std::vector<std::string> gamesPath;
        std::vector<std::string> gfxPath;
        size_t indexGame;
        size_t indexLib;

    public:
        virtual ~Menu();
        Menu();
        Menu(std::vector<std::string> gamesPath, std::vector<std::string> gfxPath);
        void moveMenu(int menu, size_t component);
        void updateComponents() override;
    };
}


#endif //CPP_ARCADE_MENU_HPP
