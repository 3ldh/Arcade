//
// Created by sauvau_m on 3/18/17.
//

#ifndef CPP_ARCADE_GUI_HPP
#define CPP_ARCADE_GUI_HPP

#include "../ArcadeInterfaces/IGUI.hpp"

namespace arcade {
    class GUI : public IGUI {
    public:
        virtual ~GUI();
        GUI();
        void createComponent(const std::string &name, TypeComponent component) override;
    };
}


#endif //CPP_ARCADE_GUI_HPP
