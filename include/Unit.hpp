//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_UNITS_HPP
#define CPP_ARCADE_UNITS_HPP


#include <utility>
#include "Map.hpp"

namespace arcade {
    class Unit {
    public:
        enum Direction {
            UP		= 2,		// MOVE THE CHARACTER UP
            DOWN	= 3,		// MOVE THE CHARACTER DOWN
            LEFT	= 4,		// MOVE THE CHARACTER LEFT
            RIGHT	= 5,		// MOVE THE CHARACTER RIGHT
        };

    protected:
        std::pair<size_t , size_t> position;
        Direction nextMove;

    public:
        virtual ~Unit();
        Unit(const std::pair<size_t, size_t> &position);
        Unit(size_t x, size_t y);
        virtual bool move(IMap const &map, Direction direction);
        virtual void moveUp();
        virtual void moveDown();
        virtual void moveLeft();
        virtual void moveRight();
        const std::pair<size_t, size_t> &getPosition() const;
        void setPosition(const std::pair<size_t, size_t> &position);
        void setPosition(size_t x, size_t y);
        Direction getNextMove() const;
        void setNextMove(Direction nextMove);
    };
}

#endif //CPP_ARCADE_UNITS_HPP
