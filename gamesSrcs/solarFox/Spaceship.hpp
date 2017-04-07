//
// Created by sauvau_m on 4/4/17.
//

#ifndef CPP_ARCADE_SPACESHIP_HPP
#define CPP_ARCADE_SPACESHIP_HPP

#include "../../include/Unit.hpp"

namespace arcade {
    class Spaceship : public Unit {

        Unit projectile;
        Direction movingDirection;

    public:
        virtual ~Spaceship();
        Spaceship(size_t x, size_t y);
        void setMovingDirection(Direction movingDirection);
        void chooseDirectionFromAxe(const arcade::Map &map, Spaceship const &player);
        Direction getMovingDirection() const;
        bool move(Map const &map);
        void shoot();
    };
}


#endif //CPP_ARCADE_SPACESHIP_HPP
