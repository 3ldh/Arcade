//
// Created by peau_c on 4/7/17.
//

#ifndef CPP_ARCADE_GFXNCURSES_H
#define CPP_ARCADE_GFXNCURSES_H

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
		WINDOW	*window;
		
		bool multipleKeyInput(arcade::Event &e);
	};
}

#endif //CPP_ARCADE_GFXNCURSES_H
