//
// Created by sauvau_m on 3/19/17.
//

#include <iostream>
#include <dirent.h>
#include "../include/Core.hpp"
#include "../include/Exception.hpp"

arcade::Core::~Core() {

}

arcade::Core::Core(std::string const &pathToLib) : gfxLibIndex(0), gameLibIndex(0) {

    gamesPath = getPathToSOFilesInDir("games");
    gfxPath = getPathToSOFilesInDir("lib");
    gameLoader = NULL;
    libLoader = NULL;

    loadGfxLib(pathToLib);
    loadGameLib(gamesPath[0]);
    coreLoop();
    //TODO map event to function
//    inputs[Event(EventType::ET_KEYBOARD, ActionType::AT_PRESSED, KB_2)] = std::bind(&arcade::Core::prevGfxLib, this);
//    inputs[Event(EventType::ET_KEYBOARD, ActionType::AT_PRESSED, KB_3)] = std::bind(&arcade::Core::nextGfxLib, this);

}

void arcade::Core::loadGfxLib(std::string const &pathToLib) {
    if (libLoader) {
        delete libLoader;
    }
    libLoader = new DLLoader<IGfxLib>(pathToLib);
    arcade::IGfxLib *lib = libLoader->getInstance("getClone");

    if (!lib)
        throw GfxLibError("Can't load GFX Library");
    currentLib = lib;
}

void arcade::Core::loadGameLib(std::string const &pathToGame) {
    if (gameLoader) {
        delete gameLoader;
    }
    gameLoader = new DLLoader<IGame>(pathToGame);
    IGame *game = gameLoader->getInstance("getClone");

    if (!game)
        throw GameLibError("Can't load Game Library");
    currentGame = game;
}

void arcade::Core::coreLoop() {

    while (true) {
        std::vector<arcade::Event> events(1);

        //getEvent
        /*currentLib->updateGUI(currentGame->getGUI());*/
        if (currentLib->pollEvent(events[0])) {
            if (events[0].kb_key == arcade::KeyboardKey::KB_ESCAPE)
                break;
            currentGame->notifyEvent(events);
        }
        currentGame->process();
        currentLib->clear();
        currentLib->display();
    }
}

void arcade::Core::prevGame() {

}

void arcade::Core::nextGame() {

}

void arcade::Core::prevGfxLib() {

}

void arcade::Core::nextGfxLib() {

}

std::vector<std::string> arcade::Core::getPathToSOFilesInDir(std::string const &pathDir) {
    std::vector<std::string> res;
    DIR *dir = opendir(pathDir.c_str());
    dirent *r;

    if (!dir) {
        throw GameLibError("lib directory is not found");
    }
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
