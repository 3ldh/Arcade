//
// Created by sauvau_m on 3/21/17.
//

#ifndef CPP_ARCADE_UICOMPONENT_HPP
#define CPP_ARCADE_UICOMPONENT_HPP

#include "../ArcadeInterfaces/IComponent.hpp"

namespace arcade {
    class UIComponent : public IComponent {
        double x, y, width, height;
        std::string text;
        Color bgColor;

    public:
        virtual ~UIComponent();
        UIComponent(double x, double y, double width, double height);

        double getX() const override;

        double getY() const override;

        double getWidth() const override;

        double getHeight() const override;

        size_t getBackgroundId() const override;

        Color getBackgroundColor() const override;

        const std::string &getText() const override;
    };
}


#endif //CPP_ARCADE_UICOMPONENT_HPP
