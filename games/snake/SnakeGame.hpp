//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP

#include "../../include/Map.hpp"
#include "../../ArcadeInterfaces/IGame.hpp"
#include "SnakeUnit.hpp"

namespace arcade {
    class SnakeGame : public IGame {
        const size_t MAP_HEIGHT = 10;
        const size_t MAP_WIDTH = 10;
        Map map;
        GameState state;

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
        std::vector<int> getSoundSToPlay() const override;
        const IMap &getCurrentMap() const override;
        const IGUI &getGUI() const override;
        void clearPlayerPos();
        void updatePlayerPos();
    };
}

#endif //CPP_ARCADE_SNAKE_HPP
