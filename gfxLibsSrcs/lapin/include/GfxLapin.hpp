//
// Created by peau_c on 3/20/17.
//

#ifndef CPP_ARCADE_GFXLAPIN_H
#define CPP_ARCADE_GFXLAPIN_H


#include <map>
#include <SFML/Graphics.hpp>
#include "LibLapin/include/lapin.h"
#include "../../../arcadeInterfaces/IGfxLib.hpp"

namespace arcade {
	class GfxLapin : public IGfxLib {
	
	public:
		virtual    ~GfxLapin();
		GfxLapin();
		
		
		bool pollEvent(Event &e) override;
		bool doesSupportSound() const override;
		void loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds) override;
		void soundControl(const Sound &sound) override;
		void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites) override;
		void updateMap(IMap const &map) override;
		void updateGUI(IGUI &gui) override;
		void display() override;
		void clear() override;
		struct bunny_window {
			size_t type;
			sf::RenderWindow *window;
			ssize_t width;
			ssize_t height;
			const char *window_name;
		};
	private:
		std::map<sf::Keyboard::Key, arcade::KeyboardKey> keyboardMap;
		std::map<sf::Event::EventType, arcade::ActionType> actionTypeMap;
		std::map<sf::Event::EventType, arcade::EventType> eventsTypeMap;
		std::vector<t_bunny_music *> sound;
		size_t windowsWidth;
		size_t windowsHeight;
		t_bunny_pixelarray *font;
		t_bunny_window *window;
		t_bunny_pixelarray *pixelarray;
		
		void drawSquare(t_bunny_accurate_position pos, t_bunny_accurate_position size, u_int32_t color);
		t_color convertArcadeColorIntoLapinColor(Color c) const;
		void tekpixel(t_bunny_pixelarray &pix, t_bunny_accurate_position pos, unsigned int col);
		void tekpixel(t_bunny_pixelarray &array, t_bunny_position pos, u_int32_t);
		void pixel_cpy(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng, t_bunny_position new_pos,
							   u_int32_t i);
		void tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng, const t_bunny_position *pos, const char *str, u_int32_t color);
		void fillPixelarrayWithBlack();
	};
}

#endif //CPP_ARCADE_GFXLAPIN_H
