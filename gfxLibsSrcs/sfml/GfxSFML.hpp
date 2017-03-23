//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_GFXSFML_HPP
#define CPP_ARCADE_GFXSFML_HPP

//#include <SFML/Graphics.hpp>
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include "../../ArcadeInterfaces/IGfxLib.hpp"

namespace arcade {
    class GfxSFML : public IGfxLib {
        const size_t WIN_HEIGHT = 800;
        const size_t WIN_WIDTH = 800;
        sf::RenderWindow window;
        std::map<sf::Keyboard::Key, arcade::KeyboardKey> eventsKeyboard;
        std::map<sf::Event::EventType, arcade::ActionType> eventsActionType;
        std::map<sf::Event::EventType, arcade::EventType > eventsType;

    public:
        virtual ~GfxSFML();
        GfxSFML();

        bool pollEvent(Event &e) override;
        bool doesSupportSound() const override;
        void loadSounds(std::vector<std::string> const &sounds) override;
        void playSound(int soundId) override;
        void updateMap(IMap const &map) override;
        void updateGUI(IGUI const &gui) override;
        void display() override;
        void clear() override;
        void openWindow();
       // void
    };
}

#endif //CPP_ARCADE_GFXSFML_HPP
