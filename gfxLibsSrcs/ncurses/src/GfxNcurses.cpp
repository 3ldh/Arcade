//
// Created by peau_c on 4/7/17.
//

#include <ncurses.h>
#include "../include/GfxNcurses.hpp"

arcade::GfxNcurses::GfxNcurses() {
	window = initscr();
	curs_set(0);
	start_color();
	getmaxyx(window, windowHeight, windowWidth);
	noecho();
	keypad(window, true);
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
	colors.push_back(colors_t(0, 0, 0, 0));
	colors.push_back(colors_t(255, 0, 0, 1));
	colors.push_back(colors_t(0, 255, 0, 2));
	colors.push_back(colors_t(255, 255, 0, 3));
	colors.push_back(colors_t(0, 0, 255, 4));
	colors.push_back(colors_t(255, 0, 255, 5));
	//colors.push_back(colors_t(0, 255, 255, 6));
	colors.push_back(colors_t(255, 255, 255, 7));
	for(short i = 0; i < 7; ++i) {
		init_pair(i, COLOR_BLACK, i);
	}
}

arcade::GfxNcurses::~GfxNcurses() {
	wclear(window);
	refresh();
	curs_set(1);
	endwin();
}

int arcade::GfxNcurses::checkColor(size_t r, size_t g, size_t b) const {
	int i = 0;
	for(auto it = colors.begin(); it < colors.end(); it++) {
		if (it->rgb[0] == (int)r && it->rgb[1] == (int)g && it->rgb[2] == (int)b)
			return (i);
		i++;
	}
	return (7);
}

void arcade::GfxNcurses::printInColor(position_t pos, const char *str, arcade::Color Color) const {
	int color = checkColor(Color.r, Color.g, Color.b);
	attron(COLOR_PAIR(color));
	mvprintw(pos.y, pos.x, "%s", str);
	attroff(COLOR_PAIR(color));
	mvcur(0, 0, 0, 0);
}

void arcade::GfxNcurses::drawCube(position_t pos, position_t size, arcade::Color color) const {
	position_t tmpPos(pos.x, pos.y);
	
	for(tmpPos.x = pos.x; tmpPos.x < pos.x + size.x; tmpPos.x++) {
		for(tmpPos.y = pos.y; tmpPos.y < pos.y + size.y; tmpPos.y++) {
			printInColor(tmpPos, " ", color);
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

void arcade::GfxNcurses::loadSounds(const std::vector<std::pair<std::string, arcade::SoundType>> &sounds) {
	(void)sounds;
}

void arcade::GfxNcurses::soundControl(const arcade::Sound &sound) {
	(void)sound;
}

void arcade::GfxNcurses::loadSprites(std::vector<std::unique_ptr<arcade::ISprite>> &&sprites) {
	(void)sprites;
}

void arcade::GfxNcurses::updateMap(const arcade::IMap &map) {
	wclear(window);
	for(size_t i = 0; i < map.getLayerNb(); i++) {
		for(size_t j = 0; j < map.getHeight(); j++) {
			for(size_t k = 0; k < map.getWidth(); k++) {
				position_t size(windowWidth / map.getWidth(), windowHeight / map.getHeight());
				position_t pos(windowWidth / map.getWidth() * k, windowHeight / map.getHeight() * j);
				if (map.at(i, j, k).getColor().full != 0)
					drawCube(pos, size, map.at(i, j, k).getColor());
			}
		}
	}
}

void arcade::GfxNcurses::updateGUI(arcade::IGUI &gui) {
	for(size_t i = 0; i < gui.size(); i++) {
		position_t pos((int) (windowWidth * gui.at(i).getX()), (int) (windowHeight * gui.at(i).getY()));
		printInColor(pos, (char *) gui.at(i).getText().c_str(), gui.at(i).getTextColor());
	}
}

void arcade::GfxNcurses::display() {
	refresh();
}

void arcade::GfxNcurses::clear() {}

extern "C" arcade::GfxNcurses *getLib() {
	return new arcade::GfxNcurses();
}
arcade::GfxNcurses::colors::colors(int r, int g, int b, arcade::Color colore) : rgb{r, g, b}, color(colore) {}

arcade::GfxNcurses::position::position(int x, int y) : x(x), y(y) {}
