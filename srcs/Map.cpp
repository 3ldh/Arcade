//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "../include/Map.hpp"
#include "../include/Layer.hpp"

arcade::ILayer &arcade::Map::operator[](size_t n) {
    return (*layer[n]);
}

const arcade::ILayer &arcade::Map::operator[](size_t n) const {
    return (*layer.at(n));
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

arcade::IMap::~IMap() {}

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
    return !(x > height || y > width ||
    operator[](layer_idx)[x][y]->getType() == arcade::TileType::BLOCK);
}

