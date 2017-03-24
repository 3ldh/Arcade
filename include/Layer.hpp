//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_LAYER_HPP
#define CPP_ARCADE_LAYER_HPP

#include <cstddef>
#include <bits/unique_ptr.h>
#include <vector>
#include "../ArcadeInterfaces/ITile.hpp"

namespace arcade {
    class Layer {
        std::vector<std::vector<std::unique_ptr<ITile> > > tiles;
        size_t width;
        size_t height;

    public:
        virtual ~Layer();
        Layer(size_t width, size_t height);
        std::vector<std::unique_ptr<ITile> > &operator[](int n);
        std::vector<std::unique_ptr<ITile> > const &operator[](int n) const;
        size_t getWidth() const;
        size_t getHeight() const;
    };
}


#endif //CPP_ARCADE_LAYER_HPP
