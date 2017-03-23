//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_LAYER_HPP
#define CPP_ARCADE_LAYER_HPP

#include "../ArcadeInterfaces/ILayer.hpp"

namespace arcade {
    class Layer : public ILayer {
        std::vector<std::vector<std::unique_ptr<ITile> > > tiles;
        size_t width;
        size_t height;

    public:
        virtual ~Layer();
        Layer(size_t width, size_t height);
        std::vector<std::unique_ptr<ITile> > &operator[](int n);
        std::vector<std::unique_ptr<ITile> > const &operator[](int n) const override;
        size_t getWidth() const override;
        size_t getHeight() const override;
    };
}


#endif //CPP_ARCADE_LAYER_HPP
