//
// Created by sauvau_m on 4/4/17.
//

#ifndef CPP_ARCADE_SOLARFOXGAME_HPP
#define CPP_ARCADE_SOLARFOXGAME_HPP

#include <unordered_map>
#include "../../arcadeInterfaces/IGame.hpp"
#include "../../include/Timer.hpp"
#include "../../include/GUI.hpp"
#include "../../include/Map.hpp"
#include "../../include/Unit.hpp"
#include "Spaceship.hpp"
#include "SpaceshipEnemy.hpp"

namespace arcade {

    class SolarFoxGame : public IGame {
             const int level0[20][20] = {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
                    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
                    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
            };
        const size_t MAP_HEIGHT = 20;
        const size_t MAP_WIDTH = 20;
        Map map;
        GameState state;
        Spaceship player;
        SpaceshipEnemy enemyLeft;
        SpaceshipEnemy enemyRight;
        SpaceshipEnemy enemyUp;
        SpaceshipEnemy enemyDown;
        std::unordered_map<arcade::KeyboardKey, arcade::Unit::Direction> inputs;
        std::vector<std::unique_ptr<Sprite>> sprites;
        std::vector<std::pair<std::string, arcade::SoundType>> sounds;
        GUI gui;
        Timer timer;
        Timer timerProjectile;

        int accelerationRate;
        void clearEnemyPos();
        void updateEnemyPos();
        void cleaPlayerPos();
        void updatePlayerPos();
        void clearProjectilesPos();
        void updateProjectilesTile();
        void processProjectile();
        void moveShipProjectiles(Spaceship &spaceship);

    public:
        virtual ~SolarFoxGame();
        SolarFoxGame();
        GameState getGameState() const override;
        void notifyEvent(std::vector<Event> &&events) override;
        void notifyNetwork(std::vector<NetworkPacket> &&events) override;
        std::vector<NetworkPacket> &&getNetworkToSend() override;
        void process() override;
        std::vector<std::unique_ptr<ISprite>> getSpritesToLoad() const override;
        std::vector<std::pair<std::string, SoundType>> getSoundsToLoad() const override;
        std::vector<Sound> getSoundsToPlay() override;
        const IMap &getCurrentMap() const override;
        IGUI &getGUI() override;
    };
}

#endif //CPP_ARCADE_SOLARFOXGAME_HPP
