//
// Created by peau_c on 3/20/17.
//

#ifndef CPP_ARCADE_GFXLAPIN_H
#define CPP_ARCADE_GFXLAPIN_H

#include "LibLapin/include/lapin.h"
#include "../../../ArcadeInterfaces/IGfxLib.hpp"

namespace arcade {
	class GfxLapin : public IGfxLib {
	
	public:
		virtual  		~GfxLapin();
						GfxLapin();
		
		bool 			pollEvent(Event &e) override;
		bool 			doesSupportSound() const override;
		void 			loadSounds(std::vector<std::string> const &sounds) override;
		void 			playSound(int soundId) override;
		void 			setSize(size_t height, size_t width) override;
		void 			setPosition(size_t y, size_t x) override;
		void 			initializeWindow() override;
		void 			updateMap(IMap const &map) override;
		void 			updateGUI(IGUI const &gui) override;
		void 			display() override;
		void 			clear() override;
	private:
		size_t			windowsWidth;
		size_t			windowsHeight;
	};
}

#endif //CPP_ARCADE_GFXLAPIN_H
