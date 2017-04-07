//
// Created by peau_c on 3/20/17.
//

#ifndef CPP_ARCADE_GFXLAPIN_H
#define CPP_ARCADE_GFXLAPIN_H


#include <map>
#include <SFML/Graphics.hpp>
#include "LibLapin/include/lapin.h"
#include "../../../ArcadeInterfaces/IGfxLib.hpp"

namespace arcade {
	class GfxLapin : public IGfxLib {
	
	public:
		virtual	~GfxLapin();
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
		struct				bunny_window
		{
			size_t											type;
			sf::RenderWindow								*window;
			ssize_t											width;
			ssize_t											height;
			const char										*window_name;
		};
	private:
		std::map<sf::Keyboard::Key, arcade::KeyboardKey>	keyboardMap;
		std::map<sf::Event::EventType, arcade::ActionType>	actionTypeMap;
		std::map<sf::Event::EventType, arcade::EventType >	eventsTypeMap;
		std::vector<t_bunny_sound	*>						sound;
		size_t												windowsWidth;
		size_t												windowsHeight;
		t_bunny_pixelarray						*font;
		t_bunny_window							*window;
		t_bunny_pixelarray						*pixelarray;
		void 									fillEvent(Event &event, ActionType type, EventType eventType, KeyboardKey key);
		int 									test_color(t_color *color);
		void 									pixel_cpy(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng, t_bunny_accurate_position new_pos, u_int32_t i);
		void tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng, t_bunny_accurate_position *pos, const std::string &str,
					 uint32_t i);
		void tekpixel(t_bunny_pixelarray *pix, t_bunny_accurate_position *pos, unsigned int col);
		void fill(t_bunny_pixelarray *pPixelarray);
		void drawSquare(t_bunny_accurate_position pos, t_bunny_accurate_position size, u_int32_t color);
		t_color convertArcadeColorIntoLapinColor(Color c);
	};
}

#endif //CPP_ARCADE_GFXLAPIN_H
