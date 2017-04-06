//
// Created by sauvau_m on 3/18/17.
//

#ifndef CPP_ARCADE_GUI_HPP
#define CPP_ARCADE_GUI_HPP

#include "../arcadeInterfaces/IGUI.hpp"
#include "UIComponent.hpp"

namespace arcade {
    class GUI : public IGUI {

    protected:
        std::vector<UIComponent *> components;

    public:
        virtual ~GUI();
        GUI();
        size_t size() const override;
        IComponent &at(std::size_t n) override;
        void addComponent(UIComponent *component);
        virtual void updateComponents();
    };
}


#endif //CPP_ARCADE_GUI_HPP
