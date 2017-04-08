//
// Created by sauvau_m on 3/19/17.
//

#include <iostream>
#include <dirent.h>
#include "../include/Core.hpp"
#include "../include/Exception.hpp"

arcade::Core::~Core() {

}

arcade::Core::Core(std::string const &pathToLib) : gfxLibIndex(0), gameLibIndex(0),
                                                   events(std::move(std::vector<arcade::Event>(0))) {

    gamesPath = getPathToSOFilesInDir("games");
    gfxPath = getPathToSOFilesInDir("lib");
    gameLoader = NULL;
    libLoader = NULL;
	currentGame = NULL;
	currentLib = NULL;

    loadGfxLib(pathToLib);
    loadGameLib(gamesPath[0]);
    menu = Menu(gamesPath, gfxPath);

    input[KB_2] = std::bind(&Core::prevGfxLib, this);
    input[KB_3] = std::bind(&Core::nextGfxLib, this);
    input[KB_4] = std::bind(&Core::prevGame, this);
    input[KB_5] = std::bind(&Core::nextGame, this);
    input[KB_8] = std::bind(&Core::restartGame, this);
    input[KB_9] = std::bind(&Core::backToMenu, this);
    launched = false;
    coreLoop();
}

void arcade::Core::loadGfxLib(std::string const &pathToLib) {
    if (currentLib) {
        delete currentLib;
        currentLib = NULL;
    }
    if (libLoader)
        delete libLoader;

    libLoader = new DLLoader<IGfxLib>(pathToLib);
    arcade::IGfxLib *lib = libLoader->getInstance("getLib");

    if (!lib)
        throw GfxLibError("Can't load GFX Library");
    currentLib = lib;
}

void arcade::Core::loadGameLib(std::string const &pathToGame) {
    if (currentGame) {
        delete currentGame;
        currentGame = NULL;
    }
    if (gameLoader)
        delete gameLoader;

    gameLoader = new DLLoader<IGame>(pathToGame);
    IGame *game = gameLoader->getInstance("getGame");

    if (!game)
        throw GameLibError("Can't load Game Library");
    currentGame = game;
}

bool arcade::Core::getEvents() {
    arcade::Event event;

    events.clear();
    while (currentLib->pollEvent(event)) {
		if (event.action == AT_PRESSED || event.action == AT_RELEASED) {
			if (event.kb_key == KB_ESCAPE || event.type == ET_QUIT)
				return (false);
			if (event.kb_key == KB_ENTER)
				launched = true;
		}
        events.push_back(event);
    }
    return (true);
}

void arcade::Core::coreLoop() {
    while (true) {
        currentLib->clear();
        if (!getEvents())
            break;
        if (events.size() > 0 && events[0].action == AT_PRESSED && input.find(events[0].kb_key) != input.end())
            input[events[0].kb_key]();
        if (launched && currentGame) {
            currentGame->notifyEvent(std::move(events));
            currentGame->process();
            currentLib->updateMap(currentGame->getCurrentMap());
            currentLib->updateGUI(currentGame->getGUI());
        } else {
            currentLib->updateGUI(menu);
        }
        currentLib->display();
    }
}

void arcade::Core::prevGame() {
    std::cout << "prevGame" << std::endl;
    --gameLibIndex;
    gameLibIndex = gameLibIndex % gamesPath.size();
    if (!launched)
        menu.moveMenu(0, gameLibIndex);
    loadGameLib(gamesPath[gameLibIndex]);
}

void arcade::Core::nextGame() {
    std::cout << "nextGame" << std::endl;
    ++gameLibIndex;
    gameLibIndex = gameLibIndex % gamesPath.size();
    if (!launched)
        menu.moveMenu(0, gameLibIndex);
    loadGameLib(gamesPath[gameLibIndex]);
}

void arcade::Core::prevGfxLib() {
    std::cout << "prevLib" << std::endl;
    --gfxLibIndex;
    gfxLibIndex = gfxLibIndex % gfxPath.size();
    if (!launched)
        menu.moveMenu(1, gfxLibIndex);
    loadGfxLib(gfxPath[gfxLibIndex]);
}

void arcade::Core::nextGfxLib() {
    std::cout << "nextLib" << std::endl;
    ++gfxLibIndex;
    gfxLibIndex = gfxLibIndex % gfxPath.size();
    if (!launched)
        menu.moveMenu(1, gfxLibIndex);
    loadGfxLib(gfxPath[gfxLibIndex]);
}

std::vector<std::string> arcade::Core::getPathToSOFilesInDir(std::string const &pathDir) {
    std::vector<std::string> res;
    DIR *dir = opendir(pathDir.c_str());
    dirent *r;

    if (!dir)
        throw GameLibError("Lib : " + pathDir + " directory doesn't exist");
    while ((r = readdir(dir))) {
        std::string name(r->d_name);
        if (stringEndWith(name, ".so"))
            res.push_back(pathDir + "/" + name);
    }
    return res;
}

bool arcade::Core::stringEndWith(std::string const &value, std::string const &end) {
    if (end.size() > value.size())
        return false;
    return std::equal(end.rbegin(), end.rend(), value.rbegin());
}

void arcade::Core::restartGame() {
    std::cout << "restart Game" << std::endl;
}

void arcade::Core::backToMenu() {
    launched = false;
}
