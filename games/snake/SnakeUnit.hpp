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

    public:
        virtual ~SnakeUnit();
        SnakeUnit(size_t x, size_t y);
        bool move(IMap const &map, Direction direction) override;
        size_t getLength() const;
        Unit &operator[](size_t n);
        bool isBodyPart(size_t x, size_t y);
        bool moveAllParts(IMap const &map, Direction direction);
        void grow();
    };
}


#endif //CPP_ARCADE_SNAKEUNIT_HPP
