//
// Created by sauvau_m on 3/18/17.
//

#ifndef CPP_ARCADE_SNAKEUNIT_HPP
#define CPP_ARCADE_SNAKEUNIT_HPP

#include <vector>
#include "../../include/Unit.hpp"

namespace arcade {
    class SnakeUnit : public Unit {
        const int NB_STARTING_PARTS = 4;
        std::vector<Unit *> parts;
        Direction movingDirection;

        bool isBodyPart(size_t x, size_t y);
        bool moveAllParts(Map const &map, Direction direction);

    public:
        virtual ~SnakeUnit();
        SnakeUnit(size_t x, size_t y);
        bool move(Map const &map, Direction direction) override;
        bool move(Map const &map);
        size_t getLength() const;
        Unit &operator[](size_t n);
        Direction getMovingDirection() const;
        void setMovingDirection(Direction movingDirection);
        bool grow(Map const &map);
    };
}


#endif //CPP_ARCADE_SNAKEUNIT_HPP
