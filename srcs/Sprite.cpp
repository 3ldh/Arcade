//
// Created by sauvau_m on 4/3/17.
//

#include "../include/Sprite.hpp"

arcade::Sprite::~Sprite() {

}

arcade::Sprite::Sprite(const std::vector<char> &ascii, const std::vector<std::string> &paths) : ascii(ascii),
                                                                                                paths(paths) {}

arcade::Sprite::Sprite(const arcade::Sprite &s) {
    ascii = s.ascii;
    paths = s.paths;
}

size_t arcade::Sprite::spritesCount() const {
    return paths.size();
}

std::string arcade::Sprite::getGraphicPath(size_t pos) const {
    return paths[pos];
}

char arcade::Sprite::getAscii(size_t pos) const {
    return ascii[pos];
}


