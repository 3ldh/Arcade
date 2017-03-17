//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP

#include "../../include/Map.hpp"
#include "../../arcade_interface/IGame.hpp"

namespace arcade {
    class Snake : public IGame {
        Map map;

    public:
        GameState getGameState() const override;
        void notifyEvent(std::vector<Event> const &events) override;
        void notifyNetwork(std::vector<NetworkPacket> const &events) override;
        std::vector<NetworkPacket> getNetworkToSend() const override;
        std::vector<std::string> getSoundsToLoad() const override;
        std::vector<int> getSoundToPlay() const override;
        const IMap &getCurrentMap() const override;
        const IMenu &getMenu() const override;
        const IGUI &getGUI() const override;
    };
}

#endif //CPP_ARCADE_SNAKE_HPP
