//
// Created by sauvau_m on 3/17/17.
//

#include "../include/Tile.hpp"

arcade::TileType arcade::Tile::getType() const {
    return type;
}

void arcade::Tile::setType(arcade::TileType type) {
    Tile::type = type;
}

arcade::TileTypeEvolution arcade::Tile::getTypeEv() const {
    return typeEv;
}

void arcade::Tile::setTypeEv(TileTypeEvolution type) {
    Tile::typeEv = type;
}

arcade::Color arcade::Tile::getColor() const {
    return color;
}

void arcade::Tile::setColor(arcade::Color color) {
    Tile::color = Color(color);
}

size_t arcade::Tile::getSpriteId() const {
    return 0;
}

size_t arcade::Tile::getSpritePos() const {
    return 0;
}

bool arcade::Tile::hasSprite() const {
    return _hasSprite;
}

double arcade::Tile::getShiftX() const {
    return 0;
}

double arcade::Tile::getShiftY() const {
    return 0;
}

arcade::Tile::~Tile() {

}

arcade::Tile::Tile(TileType type) : type(type), typeEv(EMPTY) {
}
