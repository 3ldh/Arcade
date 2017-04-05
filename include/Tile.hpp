//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_TILE_HPP
#define CPP_ARCADE_TILE_HPP

#include "../arcadeInterfaces/ITile.hpp"
#include "Sprite.hpp"

namespace arcade {
    class Tile : public ITile {
        TileType type;
        TileTypeEvolution typeEv;
        Color color;
        Sprite sprite;
        bool _hasSprite;

    private:
        Tile();

    public:
        virtual ~Tile();
        Tile(TileType type);
        TileType getType() const;
        void setType(TileType type);
        TileTypeEvolution getTypeEv() const;
        void setTypeEv(TileTypeEvolution type);
        Color getColor() const override;
        void setColor(union Color color);
        size_t getSpriteId() const override;
        size_t getSpritePos() const override;
        bool hasSprite() const override;
        double getShiftX() const override;
        double getShiftY() const override;
        const Sprite &getSprite() const;
        void setSprite(const Sprite &sprite);
    };
}

#endif //CPP_ARCADE_TILE_HPP
