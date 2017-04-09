//
// Created by sauvau_m on 4/4/17.
//

#ifndef CPP_ARCADE_SPACESHIP_HPP
#define CPP_ARCADE_SPACESHIP_HPP

#include "../../include/Unit.hpp"
#include "Projectile.hpp"

namespace arcade {
    class Spaceship : public Unit {

    protected:
        std::vector<Projectile *> projectiles;
        Direction movingDirection;
        int shootingRange;

    public:
        virtual ~Spaceship();
        Spaceship(size_t x, size_t y, int shootingRange);
        void setMovingDirection(Direction movingDirection);
        Direction getMovingDirection() const;
        std::vector<Projectile*> &getProjectiles();
        virtual bool doesProjectilesCollide(Map &map, Unit &unit);
        virtual bool move(const Map &map, size_t offsetMapBorder);
        virtual void shoot();
        virtual void clearMapForProjectile(Map &map);
        virtual void updateMapForProjectile(Map &map, Color color);
        bool doesProjectilesCollide(Map &map, std::vector<arcade::Projectile*> &units);
        int shootDirectionToSpriteId(bool player, arcade::Unit::Direction direction);
        void reset();
    };
}


#endif //CPP_ARCADE_SPACESHIP_HPP
