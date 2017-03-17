//
// Created by sauvau_m on 3/17/17.
//

#include "SnakeGames.hpp"

arcade::GameState arcade::Snake::getGameState() const {
    return nullptr;
}

void arcade::Snake::notifyEvent(const std::vector<arcade::Event> &events) {

}

void arcade::Snake::notifyNetwork(const std::vector<arcade::NetworkPacket> &events) {

}

std::vector<arcade::NetworkPacket> arcade::Snake::getNetworkToSend() const {
    return nullptr;
}

std::vector<std::string> arcade::Snake::getSoundsToLoad() const {
    return nullptr;
}

std::vector<int> arcade::Snake::getSoundToPlay() const {
    return nullptr;
}

const arcade::IMap &arcade::Snake::getCurrentMap() const {
    return map;
}

const arcade::IMenu &arcade::Snake::getMenu() const {
    return <#initializer#>;
}

const arcade::IGUI &arcade::Snake::getGUI() const {
    return <#initializer#>;
}
