//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_MAP_HPP
#define CPP_ARCADE_MAP_HPP

#include <vector>
#include <memory>
#include "../ArcadeInterfaces/IMap.hpp"
#include "Layer.hpp"

namespace arcade {
    class Map : public IMap {
        size_t width;
        size_t height;
        std::vector<Layer *> layer;

    public:
        virtual ~Map();
        Map(size_t width, size_t height, size_t nbLayer);
        Layer &operator[](size_t n);
        const Layer &operator[](size_t n) const;
        const ITile &at(size_t layer, size_t x, size_t y) const override;
        size_t getLayerNb() const override;
        size_t getWidth() const override;
        size_t getHeight() const override;
        bool isWalkable(size_t layer_idx, size_t x, size_t y) const;
    };
}

#endif //CPP_ARCADE_MAP_HPP
