//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "../include/Map.hpp"
#include "../include/Unit.hpp"

arcade::Layer &arcade::Map::operator[](size_t n) {
    return (*layer[n]);
}

const arcade::Layer &arcade::Map::operator[](size_t n) const {
    return (*layer.at(n));
}

const arcade::ITile &arcade::Map::at(size_t layer, size_t x, size_t y) const {
    return *operator[](layer)[x][y].get();
}

size_t arcade::Map::getLayerNb() const {
    return layer.size();
}

size_t arcade::Map::getWidth() const {
    return width;
}

size_t arcade::Map::getHeight() const {
    return height;
}

arcade::Map::~Map() {
    for (size_t i = 0; i < layer.size(); ++i) {
        delete layer[i];
    }
    layer.clear();
}

arcade::Map::Map(size_t width, size_t height, size_t nbLayer) : width(width), height(height) {
    for (size_t i = 0; i < nbLayer; ++i) {
        layer.push_back(new Layer(width, height));
    }
}

bool arcade::Map::isWalkable(size_t layer_idx, size_t x, size_t y) const {
    return !(x >= height || y >= width ||
    operator[](layer_idx)[x][y]->getType() == arcade::TileType::BLOCK ||
    operator[](layer_idx)[x][y]->getTypeEv() == arcade::TileTypeEvolution::PLAYER);
}

bool arcade::Map::isWalkableOffset(size_t layer_idx, size_t x, size_t y, size_t offset) const {
    return !(x >= height - offset || y >= width - offset || x < offset || y < offset ||
             operator[](layer_idx)[x][y]->getType() == arcade::TileType::BLOCK ||
             operator[](layer_idx)[x][y]->getTypeEv() == arcade::TileTypeEvolution ::PLAYER);
}

void arcade::Map::updateMapTileForUnit(arcade::Unit const &unit, size_t layer, Color color,
                                         TileType tileType, TileTypeEvolution typeEvolution, int spriteId) {
    operator[](layer)[unit.getPosition().second][unit.getPosition().first]->setType(tileType);
    operator[](layer)[unit.getPosition().second][unit.getPosition().first]->setTypeEv(typeEvolution);
    operator[](layer)[unit.getPosition().second][unit.getPosition().first]->setColor(color);
    if (spriteId)
        operator[](layer)[unit.getPosition().second][unit.getPosition().first]->setSprite(spriteId);
    else
        operator[](layer)[unit.getPosition().second][unit.getPosition().first]->removeSprite();
}