//
// Created by sauvau_m on 3/17/17.
//

#ifndef CPP_ARCADE_GFXSFML_HPP
#define CPP_ARCADE_GFXSFML_HPP

#include <SFML/Graphics.hpp>
//#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include "../../arcadeInterfaces/IGfxLib.hpp"

namespace arcade {
    class GfxSFML : public IGfxLib {

        const size_t WIN_HEIGHT = 800;
        const size_t WIN_WIDTH = 800;
        sf::RenderWindow window;
        std::map<sf::Keyboard::Key, arcade::KeyboardKey> eventsKeyboard;
        std::map<sf::Event::EventType, arcade::ActionType> eventsActionType;
        std::map<sf::Event::EventType, arcade::EventType > eventsType;
        std::vector<sf::Texture> textures;

    public:
        virtual ~GfxSFML();
        GfxSFML();
        bool pollEvent(Event &e) override;
        bool doesSupportSound() const override;
        void updateMap(IMap const &map) override;
        void display() override;
        void clear() override;
        void loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds) override;
        void soundControl(const Sound &sound) override;
        void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites) override;
        void updateGUI(IGUI &gui) override;
    };
}

#endif //CPP_ARCADE_GFXSFML_HPP
