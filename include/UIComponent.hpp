//
// Created by sauvau_m on 3/21/17.
//

#ifndef CPP_ARCADE_UICOMPONENT_HPP
#define CPP_ARCADE_UICOMPONENT_HPP

#include "../arcadeInterfaces/IComponent.hpp"
#include "Sprite.hpp"

namespace arcade {
    class UIComponent : public IComponent {
        double x, y, width, height;
        std::string text;
        Color textColor;
        Color bgColor;
        Sprite sprite;
        bool _hasSprite;
        bool hover;
        bool selected;

    public:
        virtual ~UIComponent();
        UIComponent(double x, double y, double width, double height);
        double getX() const override;
        double getY() const override;
        double getWidth() const override;
        double getHeight() const override;
        size_t getBackgroundId() const override;
        Color getBackgroundColor() const override;
        void setText(const std::string &text);
        void setBgColor(const Color &bgColor);
        void setTextColor(const Color &textColor);
        const std::string &getText() const override;
        bool hasSprite() const override;
        Color getTextColor() const override;
        void setClicked() override;
        bool isHover() const;
        void setHover(bool hover);
        bool isSelected() const;
        void setSelected(bool selected);
        void toogle();
    };
}


#endif //CPP_ARCADE_UICOMPONENT_HPP
