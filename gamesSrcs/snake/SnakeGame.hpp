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
#include "../../include/Sprite.hpp"
#include "../../include/GUI.hpp"

namespace arcade {
    class SnakeGame : public IGame {
        const size_t MAP_HEIGHT = 20;
        const size_t MAP_WIDTH = 20;
        Map map;
        GameState state;
        std::unordered_map<arcade::KeyboardKey, arcade::Unit::Direction > inputs;
        std::vector<std::unique_ptr<ISprite> > &&sprites;
        std::vector<std::pair<std::string, arcade::SoundType>> sounds;
        GUI gui;

    public:
    //TODO pass it private
        SnakeUnit snake;
        virtual ~SnakeGame();
        SnakeGame();
        GameState getGameState() const override;
        void notifyEvent(std::vector<Event> &&events) override;
        void notifyNetwork(std::vector<NetworkPacket> &&events) override;
        std::vector<NetworkPacket> &&getNetworkToSend() override;
        std::vector<std::unique_ptr<ISprite>> &&getSpritesToLoad() const override;
        std::vector<std::pair<std::string, SoundType>> getSoundsToLoad() const override;
        IGUI &getGUI() override;
        std::vector<int> &&getSoundsToPlay() override;
        const IMap &getCurrentMap() const override;
        const Map &getMap() const;
        void process() override;
        void spawnApple();
        void takeApple(size_t x, size_t y);
        void clearPlayerPos();
        void updatePlayerPos();
    };
}

#endif //CPP_ARCADE_SNAKE_HPP
