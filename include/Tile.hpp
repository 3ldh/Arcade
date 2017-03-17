//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_TILE_HPP
#define CPP_ARCADE_TILE_HPP

#include "../arcade_interface/ITile.hpp"

namespace arcade {
    class Tile : public ITile{
        TileType type;
        TileTypeEvolution typeEv;

    private:
        Tile();
    public:
        virtual ~Tile();
        Tile(TileType type);
        TileType getType() const override;
        void setType(TileType type) override;
        TileTypeEvolution getTypeEv() const override;
        void setTypeEv(TileTypeEvolution type) override;
        Color getColor() const override;
        void setColor(union Color color) override;
        size_t getSpriteId() const override;
        size_t getSpritePos() const override;
        void nextSprite() override;
        void prevSprite() override;
        void setSpritePos(size_t pos) override;
        void setSprite(size_t id) override;
    };
}

#endif //CPP_ARCADE_TILE_HPP
