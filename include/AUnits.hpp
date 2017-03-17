//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_UNITS_HPP
#define CPP_ARCADE_UNITS_HPP


#include <utility>

namespace arcade {
    class Units {
        enum Direction {
            UP		= 2,		// MOVE THE CHARACTER UP
            DOWN	= 3,		// MOVE THE CHARACTER DOWN
            LEFT	= 4,		// MOVE THE CHARACTER LEFT
            RIGHT	= 5,		// MOVE THE CHARACTER RIGHT
        };
    protected:
        std::pair<int, int> position;
        Direction nextMove;

    public:
        virtual ~Units();
        Units(const std::pair<int, int> &position);
        Units(int x, int y);
        void move(Direction direction);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        const std::pair<int, int> &getPosition() const;
        void setPosition(const std::pair<int, int> &position);
        void setPosition(int x, int y);
        Direction getNextMove() const;
        void setNextMove(Direction nextMove);
    };
}

#endif //CPP_ARCADE_UNITS_HPP
