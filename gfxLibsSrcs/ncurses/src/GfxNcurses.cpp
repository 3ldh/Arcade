//
// Created by peau_c on 4/7/17.
//

#include <ncurses.h>
#include "../include/GfxNcurses.hpp"

arcade::GfxNcurses::GfxNcurses() {
	
	window = initscr();
	noecho();
	keypad(window, true);
	timeout(0);
}

arcade::GfxNcurses::~GfxNcurses() {
	endwin();
}

bool arcade::GfxNcurses::multipleKeyInput(arcade::Event &e) {
	int ch;
	
	if ((ch = getch()) == ERR)
		return (1);
	if (ch == 'a')
		exit(1);
	return (0);
}


bool arcade::GfxNcurses::pollEvent(arcade::Event &e) {
	int c = 0;
	if ((c = getch()) == ERR) {
		return false;
	}
	if (c == 'a')
		exit (1);
}

bool arcade::GfxNcurses::doesSupportSound() const {
	return false;
}

void arcade::GfxNcurses::loadSounds(const std::vector<std::pair<std::string, arcade::SoundType>> &sounds) {}

void arcade::GfxNcurses::soundControl(const arcade::Sound &sound) {}

void arcade::GfxNcurses::loadSprites(std::vector<std::unique_ptr<arcade::ISprite>> &&sprites) {}

void arcade::GfxNcurses::updateMap(const arcade::IMap &map) {

}

void arcade::GfxNcurses::updateGUI(arcade::IGUI &gui) {

}

void arcade::GfxNcurses::display() {

}

void arcade::GfxNcurses::clear() {

}

extern "C" arcade::GfxNcurses *getLib() {
	return new arcade::GfxNcurses();
}
