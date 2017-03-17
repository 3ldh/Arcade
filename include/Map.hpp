//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_MAP_HPP
#define CPP_ARCADE_MAP_HPP

#include "../arcade_interface/IMap.hpp"

namespace arcade {
    class Map : public IMap {
        size_t width;
        size_t height;
        std::vector<ILayer *> layer;

    public:
        virtual ~Map();
        Map(size_t width, size_t height, size_t nbLayer);
        ILayer &operator[](size_t n) override;
        size_t getLayerNb() const override;
        size_t getWidth() const override;
        size_t getHeight() const override;
    };
}

#endif //CPP_ARCADE_MAP_HPP
