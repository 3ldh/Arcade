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

    loadGfxLib(pathToLib);
    currentLib->display();
    loadGameLib(gamesPath[0]);

    //TODO map event to function
//    input[Event(EventType::ET_KEYBOARD, ActionType::AT_PRESSED, KB_2)] = std::bind(&arcade::Core::prevGfxLib, this);
//    input[Event(EventType::ET_KEYBOARD, ActionType::AT_PRESSED, KB_3)] = std::bind(&arcade::Core::nextGfxLib, this);

}

void arcade::Core::loadGfxLib(std::string const &pathToLib) {
    DLLoader<IGfxLib> loader(pathToLib);
    IGfxLib *lib = loader.getInstance("getClone");

    if (!lib)
        throw GfxLibError("Can't load GFX Library");
    currentLib = lib;
}

void arcade::Core::loadGameLib(std::string const &pathToGame) {
    DLLoader<IGame> loader(pathToGame);
    IGame *game = loader.getInstance("getClone");

    if (!game)
        throw GameLibError("Can't load Game Library");
    currentGame = game;
}

void arcade::Core::coreLoop() {
    while (true) {

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