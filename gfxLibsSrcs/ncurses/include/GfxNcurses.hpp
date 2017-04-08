//
// Created by peau_c on 4/7/17.
//

#ifndef CPP_ARCADE_GFXNCURSES_H
#define CPP_ARCADE_GFXNCURSES_H

#include <map>
#include "../../../arcadeInterfaces/IGfxLib.hpp"


namespace arcade {
	class GfxNcurses : public IGfxLib {
	public:
		GfxNcurses();
		~GfxNcurses();
		
		bool pollEvent(Event &e) override;
		bool doesSupportSound() const override;
		void loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds) override;
		void soundControl(const Sound &sound) override;
		void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites) override;
		void updateMap(IMap const &map) override;
		void updateGUI(IGUI &gui) override;
		void display() override;
		void clear() override;
	
	private:
		typedef struct	colors {
			colors(int r, int g, int b, arcade::Color color);
			int				rgb[3];
			arcade::Color	color;
		}			colors_t;
		typedef struct	position {
		public:
			position(int x, int y);
			int x;
			int y;
		}				position_t;
		std::vector<colors_t> colors;
		WINDOW	*window;
		std::map<int, arcade::KeyboardKey> keyboardMap;
		size_t windowHeight;
		size_t windowWidth;
		void drawCube(position_t pos, position_t size, arcade::Color color);
		int checkColor(size_t r, size_t g, size_t b);
		void makeASquareOutOfPos(position_t &position);
		void printInColor(position_t pos, const char *str, Color color);
	};
}

#endif //CPP_ARCADE_GFXNCURSES_H
