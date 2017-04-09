//
// Created by sauvau_m on 4/7/17.
//

#ifndef CPP_ARCADE_PROJECTILE_HPP
#define CPP_ARCADE_PROJECTILE_HPP

#include "../../include/Unit.hpp"

namespace arcade {

    class Projectile : public Unit {

        std::pair<size_t, size_t> initialPosition;
        Direction direction;
        int maxRange;

    public:
        virtual ~Projectile();
        Projectile(size_t x, size_t y, Direction direction, int maxRange);
        bool doesCollide(Unit const &unit) const;
        bool move(Map const &map, Unit const &unit);
        Direction getDirection() const;
    };
}


#endif //CPP_ARCADE_PROJECTILE_HPP
