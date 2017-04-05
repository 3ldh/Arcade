//
// Created by sauvau_m on 3/19/17.
//

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <functional>
#include <map>
#include "../arcadeInterfaces/IGfxLib.hpp"
#include "../arcadeInterfaces/IGame.hpp"
#include "DLLoader.hpp"
#include "Menu.hpp"

namespace arcade {
    class Core {
        DLLoader<IGfxLib> *libLoader;
        DLLoader<IGame> *gameLoader;
        IGfxLib *currentLib;
        IGame *currentGame;
        std::vector<std::string> gamesPath;
        std::vector<std::string> gfxPath;
        size_t gfxLibIndex;
        size_t gameLibIndex;
        std::map<arcade::KeyboardKey, std::function<void()>> input;
		std::vector<arcade::Event> &&events;
		Menu menu;
        bool launched;

        bool stringEndWith(std::string const &value, std::string const &end);
        std::vector<std::string> getPathToSOFilesInDir(std::string const &pathDir);
		bool getEvents();

    public:
        virtual ~Core();
        Core(std::string const &pathToLib);
        void loadGfxLib(std::string const &pathToLib);
        void loadGameLib(std::string const &pathToGame);
        void coreLoop();
        void prevGame();
        void nextGame();
        void prevGfxLib();
        void nextGfxLib();
        void restartGame();
        void backToMenu();
	};
}


#endif //CPP_ARCADE_CORE_HPP
