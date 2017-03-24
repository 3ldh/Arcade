//
// Created by sauvau_m on 3/17/17.
//

#include "../include/Layer.hpp"
#include "../include/Tile.hpp"

arcade::Layer::~Layer() {
/*    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
          delete tiles[i][j];
        }
    }*/
}

std::vector<std::unique_ptr<arcade::ITile> > &arcade::Layer::operator[](int n) {
    return tiles[n];
}

std::vector<std::unique_ptr<arcade::ITile> > const &arcade::Layer::operator[](int n) const {
    return tiles.at(n);
}

size_t arcade::Layer::getWidth() const {
    return width;
}

size_t arcade::Layer::getHeight() const {
    return height;
}

arcade::Layer::Layer(size_t width, size_t height) : width(width), height(height) {
    for (size_t i = 0; i < height; ++i) {
        std::vector<std::unique_ptr<ITile> > vec;
        for (size_t j = 0; j < width; ++j) {
            //vec.push_back(new Tile(arcade::TileType::EMPTY));
            //TODO make_unique not working
            vec.push_back(std::unique_ptr<ITile>(new Tile(arcade::TileType::EMPTY)));
        }
        tiles.push_back(std::move(vec));
    }
}