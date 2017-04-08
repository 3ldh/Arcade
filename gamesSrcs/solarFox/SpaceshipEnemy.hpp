//
// Created by sauvau_m on 4/7/17.
//

#ifndef CPP_ARCADE_SPACESHIPENEMY_HPP
#define CPP_ARCADE_SPACESHIPENEMY_HPP

#include "Spaceship.hpp"

namespace arcade {

    class SpaceshipEnemy : public Spaceship {

    public:
        virtual ~SpaceshipEnemy();
        SpaceshipEnemy(size_t x, size_t y, int shootingRange);
        bool move(const Map &map);
        std::pair<int, int> posDiffWithPlayer(Spaceship const &player);
        void chooseToShoot(const Map &map, Spaceship const &player);
        bool canMove(const Map &map);
        void shoot(const Map &map);
        virtual void clearMapForProjectile(Map &map);
        virtual void updateMapForProjectile(Map &map);
    };
}


#endif //CPP_ARCADE_SPACESHIPENEMY_HPP
