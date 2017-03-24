//
// Created by sauvau_m on 3/18/17.
//

#ifndef CPP_ARCADE_GUI_HPP
#define CPP_ARCADE_GUI_HPP

#include "../ArcadeInterfaces/IGUI.hpp"

namespace arcade {
    class GUI : public IGUI {

    protected:
        std::vector<IComponent *> components;

    public:
        virtual ~GUI();
        GUI();
        size_t size() const override;
        const IComponent &at(std::size_t n) const override;
        std::vector<arcade::IComponent *>::const_iterator begin() const override;
        std::vector<arcade::IComponent *>::const_iterator end() const override;
        void addComponent(IComponent *component);

    };
}


#endif //CPP_ARCADE_GUI_HPP
