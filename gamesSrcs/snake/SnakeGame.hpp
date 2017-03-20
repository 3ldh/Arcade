//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP

#include <map>
#include <functional>
#include <unordered_map>
#include "../../include/Map.hpp"
#include "../../ArcadeInterfaces/IGame.hpp"
#include "SnakeUnit.hpp"

namespace arcade {
    class SnakeGame : public IGame {
        const size_t MAP_HEIGHT = 10;
        const size_t MAP_WIDTH = 10;
        Map map;
        GameState state;
        std::unordered_map<arcade::KeyboardKey, arcade::Unit::Direction > inputs;

    public:
    //TODO pass it private
        SnakeUnit snake;

        virtual ~SnakeGame();
        SnakeGame();
        GameState getGameState() const override;
        void notifyEvent(std::vector<Event> const &events) override;
        void notifyNetwork(std::vector<NetworkPacket> const &events) override;
        std::vector<NetworkPacket> getNetworkToSend() const override;
        std::vector<std::string> getSoundsToLoad() const override;
        std::vector<int> getSoundsToPlay() override;
        const IMap &getCurrentMap() const override;
        const Map &getMap() const;
        const IGUI &getGUI() const override;
        void process() override;
        void spawnApple();
        void takeApple(size_t x, size_t y);
        void clearPlayerPos();
        void updatePlayerPos();
    };
}

#endif //CPP_ARCADE_SNAKE_HPP
