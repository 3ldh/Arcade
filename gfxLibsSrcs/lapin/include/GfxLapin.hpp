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
		std::vector<t_bunny_sound *> sound;
		size_t windowsWidth;
		size_t windowsHeight;
		t_bunny_pixelarray *font;
		t_bunny_window *window;
		t_bunny_pixelarray *pixelarray;
		void fillEvent(Event &event, ActionType type, EventType eventType, KeyboardKey key);
		void fill(t_bunny_pixelarray *pPixelarray);
		void drawSquare(t_bunny_accurate_position pos, t_bunny_accurate_position size, u_int32_t color);
		t_color convertArcadeColorIntoLapinColor(Color c);
		t_bunny_position pos_(int x, int y);
		void write_txt_next(t_bunny_position *offset, t_bunny_pixelarray *pix_ar, t_bunny_pixelarray *letter);
		void write_txt(t_bunny_pixelarray *pix_ar, t_bunny_pixelarray *font, char *str, t_bunny_position);
		t_bunny_position offset_center_txt(char *str);
		void write_png(t_bunny_pixelarray *pix_ar, t_bunny_pixelarray *font, char *str);
		void my_fill(t_bunny_pixelarray *pix, uint32_t i);
		t_bunny_pixelarray *get_letter(t_bunny_pixelarray *f, int index);
		void my_blit(t_bunny_pixelarray *pix_ar, t_bunny_pixelarray *pix_ar2, t_bunny_position offset);
		t_color blend(t_color bg, t_color fg);
		void tekpixel(t_bunny_pixelarray *pix, t_bunny_accurate_position *pos, unsigned int col);
	};
}

#endif //CPP_ARCADE_GFXLAPIN_H
