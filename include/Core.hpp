//
// Created by sauvau_m on 3/19/17.
//

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <functional>
#include <map>
#include "../ArcadeInterfaces/IGfxLib.hpp"
#include "../ArcadeInterfaces/IGame.hpp"
#include "DLLoader.hpp"

namespace arcade {
    class Core {
        DLLoader<IGfxLib> *libLoader;
        DLLoader<IGame> *gameLoader;

        IGfxLib *currentLib;
        IGame *currentGame;
        std::vector<std::string> gamesPath;
        std::vector<std::string> gfxPath;
        int gfxLibIndex;
        int gameLibIndex;
        std::map<arcade::KeyboardKey, std::function<void(void)> > input;

        bool stringEndWith(std::string const &value, std::string const &end);
        std::vector<std::string> getPathToSOFilesInDir(std::string const &pathDir);
		bool getEvents(std::vector<arcade::Event> &);

    public:
        virtual ~Core();
        Core(std::string const &pathToLib);
        void loadGfxLib(std::string const &pathToLib);
        void loadGameLib(std::string const &pathToGame);
        void coreLoop();
        void prevGame();
        void nextGame();
        void prevGfxLib(void);
        void nextGfxLib();
        void switchMenu();
        void menuUp();
        void menuDown();
	};
}


#endif //CPP_ARCADE_CORE_HPP
