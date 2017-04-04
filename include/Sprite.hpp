//
// Created by sauvau_m on 4/3/17.
//

#ifndef CPP_ARCADE_SPRITE_HPP
#define CPP_ARCADE_SPRITE_HPP

#include <vector>
#include "../ArcadeInterfaces/ISprite.hpp"

namespace arcade {

    class Sprite : public ISprite {

        std::vector<char > ascii;
        std::vector<std::string > paths;

    public:
        virtual ~Sprite();

        Sprite(const std::vector<char> &ascii = std::vector<char>(), const std::vector<std::string> &paths = std::vector<std::string>());
        size_t spritesCount() const override;
        std::string getGraphicPath(size_t pos) const override;
        char getAscii(size_t pos) const override;
    };
}

#endif //CPP_ARCADE_SPRITE_HPP
