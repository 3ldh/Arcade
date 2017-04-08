//
// Created by peau_c on 4/7/17.
//

#include <ncurses.h>
#include "../include/GfxNcurses.hpp"

arcade::GfxNcurses::GfxNcurses() {
	
	//TODO: check max size with map;
	window = initscr();
	start_color();
	getmaxyx(window, windowHeight, windowWidth);
	noecho();
	keypad(window, true);
	dprintf(2, "Lucas je te basie\n");
	timeout(0);
	keyboardMap['a'] = KB_A;
	keyboardMap['b'] = KB_B;
	keyboardMap['c'] = KB_C;
	keyboardMap['d'] = KB_D;
	keyboardMap['f'] = KB_F;
	keyboardMap['g'] = KB_G;
	keyboardMap['h'] = KB_H;
	keyboardMap['i'] = KB_I;
	keyboardMap['j'] = KB_J;
	keyboardMap['k'] = KB_K;
	keyboardMap['l'] = KB_L;
	keyboardMap['m'] = KB_M;
	keyboardMap['n'] = KB_N;
	keyboardMap['o'] = KB_O;
	keyboardMap['p'] = KB_P;
	keyboardMap['q'] = KB_Q;
	keyboardMap['r'] = KB_R;
	keyboardMap['s'] = KB_S;
	keyboardMap['t'] = KB_T;
	keyboardMap['u'] = KB_U;
	keyboardMap['v'] = KB_V;
	keyboardMap['w'] = KB_W;
	keyboardMap['x'] = KB_X;
	keyboardMap['y'] = KB_Y;
	keyboardMap['z'] = KB_Z;
	keyboardMap['1'] = KB_1;
	keyboardMap['2'] = KB_2;
	keyboardMap['3'] = KB_3;
	keyboardMap['4'] = KB_4;
	keyboardMap['5'] = KB_5;
	keyboardMap['6'] = KB_6;
	keyboardMap['7'] = KB_7;
	keyboardMap['8'] = KB_8;
	keyboardMap['9'] = KB_9;
	keyboardMap[' '] = KB_SPACE;
	keyboardMap['\n'] = KB_ENTER;
	keyboardMap[KEY_UP] = KB_ARROW_UP;
	keyboardMap[KEY_DOWN] = KB_ARROW_DOWN;
	keyboardMap[KEY_LEFT] = KB_ARROW_LEFT;
	keyboardMap[KEY_RIGHT] = KB_ARROW_RIGHT;
	keyboardMap[27] = KB_ESCAPE;
}

arcade::GfxNcurses::~GfxNcurses() {
	endwin();
}

void arcade::GfxNcurses::createColor(size_t r, size_t g, size_t b) {
	dprintf(2, "%lu %lu %lu\n", r * 3, g * 3, b * 3);
	init_color(COLOR_RED, (short) (r * 3), (short) (g * 3), (short) (b * 3));
	init_pair(1, COLOR_RED, COLOR_BLACK);
}

void arcade::GfxNcurses::printInColor(position_t pos, char *str, arcade::Color color) {
	createColor(color.r, color.g, color.b);
	attron(COLOR_PAIR(1));
	mvprintw(pos.y, pos.x, "%s", str);
	attroff(COLOR_PAIR(1));
}

void arcade::GfxNcurses::drawCube(position_t pos, position_t size, arcade::Color color) {
	position_t	tmpPos(pos.x, pos.y);

	for (tmpPos.x = pos.x; tmpPos.x < pos.x + size.x; tmpPos.x++) {
		for (tmpPos.y = pos.y; tmpPos.y < pos.y + size.y; tmpPos.y++) {
			printInColor(tmpPos, ";", )
		}
	}
}

bool arcade::GfxNcurses::pollEvent(arcade::Event &e) {
	int c = 0;
	if ((c = getch()) == ERR) {
		return false;
	}
	e.type = EventType::ET_KEYBOARD;
	e.action = ActionType::AT_PRESSED;
	auto it = keyboardMap.find(c);
	e.kb_key = (it == keyboardMap.end() ? KB_NONE : it->second);
	return (true);
}

bool arcade::GfxNcurses::doesSupportSound() const {
	return false;
}

void arcade::GfxNcurses::loadSounds(const std::vector<std::pair<std::string, arcade::SoundType>> &sounds) {}

void arcade::GfxNcurses::soundControl(const arcade::Sound &sound) {}

void arcade::GfxNcurses::loadSprites(std::vector<std::unique_ptr<arcade::ISprite>> &&sprites) {}

void arcade::GfxNcurses::makeASquareOutOfPos(position_t &position) {
	int max = (position.x > position.y ? position.x	: position.y);
	
	position.x = max;
	position.y = max;
}

void arcade::GfxNcurses::updateMap(const arcade::IMap &map) {
	
	for (size_t i = 0; i < map.getLayerNb(); i++) {
		for (size_t j = 0; j < map.getHeight(); j++) {
			for (size_t k = 0; k < map.getWidth(); k++) {
				position_t size(windowWidth / map.getWidth() - 1, windowHeight / map.getHeight() - 1);
				makeASquareOutOfPos(size);
				position_t pos(windowWidth / map.getWidth() * k, windowHeight / map.getHeight() * j);
				drawCube(pos, size, map.at(i, j, k).getColor());
			}
		}
	}
}

void arcade::GfxNcurses::updateGUI(arcade::IGUI &gui) {
	for(size_t i = 0; i < gui.size(); i++) {
		mvwprintw(window, gui.at(i).getY(), gui.at(i).getX(), gui.at(i).getText().c_str());
	}
}
void arcade::GfxNcurses::display() {
	refresh();
}

void arcade::GfxNcurses::clear() {
//	wclear(window);
}

extern "C" arcade::GfxNcurses *getLib() {
	return new arcade::GfxNcurses();
}
