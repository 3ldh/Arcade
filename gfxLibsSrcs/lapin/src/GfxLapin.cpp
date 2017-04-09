//
// Created by peau_c on 3/20/17.
//

#include <limits>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../include/GfxLapin.hpp"

arcade::GfxLapin::GfxLapin() {
	bunny_enable_full_blit(true);
	font = bunny_load_pixelarray("assets/font.png");
	if (!font)
		std::cerr << "Missing ./assets/font.png unable to print text in LibLapin" << std::endl;
	window = bunny_start(800, 800, false, "Mathieu");
	pixelarray = bunny_new_pixelarray(800, 800);
	windowsHeight = 800;
	windowsWidth = 800;
	bunny_fill(&window->buffer, BLUE);
	
	keyboardMap[sf::Keyboard::Key::A] = KB_A; /// A key
	keyboardMap[sf::Keyboard::Key::B] = KB_B; /// B key
	keyboardMap[sf::Keyboard::Key::C] = KB_C; /// C key
	keyboardMap[sf::Keyboard::Key::D] = KB_D; /// D key
	keyboardMap[sf::Keyboard::Key::E] = KB_E; /// E key
	keyboardMap[sf::Keyboard::Key::F] = KB_F; /// F key
	keyboardMap[sf::Keyboard::Key::G] = KB_G; /// G key
	keyboardMap[sf::Keyboard::Key::H] = KB_H; /// H key
	keyboardMap[sf::Keyboard::Key::I] = KB_I; /// I key
	keyboardMap[sf::Keyboard::Key::J] = KB_J; /// J key
	keyboardMap[sf::Keyboard::Key::K] = KB_K; /// K key
	keyboardMap[sf::Keyboard::Key::L] = KB_L; /// L key
	keyboardMap[sf::Keyboard::Key::M] = KB_M; /// M key
	keyboardMap[sf::Keyboard::Key::N] = KB_N; /// N key
	keyboardMap[sf::Keyboard::Key::O] = KB_O; /// O key
	keyboardMap[sf::Keyboard::Key::P] = KB_P; /// P key
	keyboardMap[sf::Keyboard::Key::Q] = KB_Q; /// Q key
	keyboardMap[sf::Keyboard::Key::R] = KB_R; /// R key
	keyboardMap[sf::Keyboard::Key::S] = KB_S; /// S key
	keyboardMap[sf::Keyboard::Key::T] = KB_T; /// T key
	keyboardMap[sf::Keyboard::Key::U] = KB_U; /// U key
	keyboardMap[sf::Keyboard::Key::V] = KB_V; /// V key
	keyboardMap[sf::Keyboard::Key::X] = KB_X; /// X key
	keyboardMap[sf::Keyboard::Key::Y] = KB_Y; /// Y key
	keyboardMap[sf::Keyboard::Key::Z] = KB_Z; /// Z key
	keyboardMap[sf::Keyboard::Key::Num0] = KB_0; /// 0 key
	keyboardMap[sf::Keyboard::Key::Num1] = KB_1; /// 1 key
	keyboardMap[sf::Keyboard::Key::Num2] = KB_2; /// 2 key
	keyboardMap[sf::Keyboard::Key::Num3] = KB_3; /// 3 key
	keyboardMap[sf::Keyboard::Key::Num4] = KB_4; /// 4 key
	keyboardMap[sf::Keyboard::Key::Num5] = KB_5; /// 5 key
	keyboardMap[sf::Keyboard::Key::Num6] = KB_6; /// 6 key
	keyboardMap[sf::Keyboard::Key::Num7] = KB_7; /// 7 key
	keyboardMap[sf::Keyboard::Key::Num8] = KB_8; /// 8 key
	keyboardMap[sf::Keyboard::Key::Num9] = KB_9; /// 9 key
	keyboardMap[sf::Keyboard::Key::Left] = KB_ARROW_LEFT; /// Left arrow key
	keyboardMap[sf::Keyboard::Key::Right] = KB_ARROW_RIGHT;/// Right arrow key
	keyboardMap[sf::Keyboard::Key::Up] = KB_ARROW_UP; /// Up arrow key
	keyboardMap[sf::Keyboard::Key::Down] = KB_ARROW_DOWN; /// Down arrow key
	keyboardMap[sf::Keyboard::Key::Space] = KB_SPACE; /// Space key
	keyboardMap[sf::Keyboard::Key::Return] = KB_ENTER; /// Enter/Carriage return key
	keyboardMap[sf::Keyboard::Key::BackSpace] = KB_BACKSPACE; /// Backspace key
	keyboardMap[sf::Keyboard::Key::LControl] = KB_LCTRL; /// Left Control key
	keyboardMap[sf::Keyboard::Key::RControl] = KB_RCTRL; /// Right Control key
	keyboardMap[sf::Keyboard::Key::LAlt] = KB_LALT; /// Left Alt key
	keyboardMap[sf::Keyboard::Key::RAlt] = KB_RALT; /// Right Alt key
	keyboardMap[sf::Keyboard::Key::LShift] = KB_LSHIFT; /// Left Shift key
	keyboardMap[sf::Keyboard::Key::RShift] = KB_RSHIFT; /// Right Shift key
	keyboardMap[sf::Keyboard::Key::Tab] = KB_TAB; /// Tabulation key
	keyboardMap[sf::Keyboard::Key::Escape] = KB_ESCAPE; /// Escape key
	keyboardMap[sf::Keyboard::Key::PageUp] = KB_PAGEUP; /// Page up key
	keyboardMap[sf::Keyboard::Key::PageDown] = KB_PAGEDOWN; /// Page down
	keyboardMap[sf::Keyboard::Key::Home] = KB_HOME; /// Home key
	keyboardMap[sf::Keyboard::Key::End] = KB_END; /// End key
	keyboardMap[sf::Keyboard::Key::F1] = KB_FN1; /// Function key 1 (F1)
	keyboardMap[sf::Keyboard::Key::F2] = KB_FN2; /// Function key 2 (F2)
	keyboardMap[sf::Keyboard::Key::F3] = KB_FN3; /// Function key 3 (F3)
	keyboardMap[sf::Keyboard::Key::F4] = KB_FN4; /// Function key 4 (F4)
	keyboardMap[sf::Keyboard::Key::F5] = KB_FN5; /// Function key 5 (F5)
	keyboardMap[sf::Keyboard::Key::F6] = KB_FN6; /// Function key 6 (F6)
	keyboardMap[sf::Keyboard::Key::F7] = KB_FN7; /// Function key 7 (F7)
	keyboardMap[sf::Keyboard::Key::F8] = KB_FN8; /// Function key 8 (F8)
	keyboardMap[sf::Keyboard::Key::F9] = KB_FN9; /// Function key 9 (F9)
	keyboardMap[sf::Keyboard::Key::F10] = KB_FN10; /// Function key 10 (F10)
	keyboardMap[sf::Keyboard::Key::F11] = KB_FN11; /// Function key 11 (F11)
	keyboardMap[sf::Keyboard::Key::F12] = KB_FN12; /// Function key 12 (F12)
	keyboardMap[sf::Keyboard::Key::Comma] = KB_COMMA; /// Comma key (,)
	keyboardMap[sf::Keyboard::Key::Period] = KB_DOT; /// Dot (period) key (.)
	keyboardMap[sf::Keyboard::Key::Slash] = KB_SLASH; /// Slash key (/)
	keyboardMap[sf::Keyboard::Key::SemiColon] = KB_SEMICOLON; /// Semicolon key (;)
	keyboardMap[sf::Keyboard::Key::Quote] = KB_SIMPLEQUOTE; /// Simple quote key (')
	keyboardMap[sf::Keyboard::Key::LBracket] = KB_LEFTBRACKET; /// Left bracket key ([)
	keyboardMap[sf::Keyboard::Key::RBracket] = KB_RIGHTBRACKET;/// Right bracker key (])
	keyboardMap[sf::Keyboard::Key::BackSlash] = KB_BACKSLASH; /// Backslash key (\)
	keyboardMap[sf::Keyboard::Key::Multiply] = KB_ASTERISK; /// Asterisk key (*)
	keyboardMap[sf::Keyboard::Key::Subtract] = KB_MINUS; /// Minus symbol key (-)
	keyboardMap[sf::Keyboard::Key::Add] = KB_PLUS; /// Plus symbol key (+)
	keyboardMap[sf::Keyboard::Key::Equal] = KB_EQUALS;
	keyboardMap[sf::Keyboard::Key::Delete] = KB_DELETE;
	actionTypeMap[sf::Event::KeyPressed] = AT_PRESSED;
	actionTypeMap[sf::Event::KeyReleased] = AT_RELEASED;
	eventsTypeMap[sf::Event::Closed] = ET_QUIT;
	eventsTypeMap[sf::Event::KeyPressed] = ET_KEYBOARD;
	eventsTypeMap[sf::Event::KeyReleased] = ET_KEYBOARD;
}

arcade::GfxLapin::~GfxLapin() {
	bunny_stop(window);
	bunny_delete_clipable(&pixelarray->clipable);
}

bool arcade::GfxLapin::pollEvent(arcade::Event &e) {
	sf::Event eventSFML;
	bunny_window *window;
	
	window = (bunny_window *) this->window;
	bool event = window->window->pollEvent(eventSFML);
	if (!event)
		return (false);
	auto itEventType = eventsTypeMap.find(eventSFML.type);
	e.type = (itEventType != eventsTypeMap.end() ? itEventType->second : ET_NONE);
	auto itActionType = actionTypeMap.find(eventSFML.type);
	e.action = (itActionType != actionTypeMap.end() ? itActionType->second : AT_NONE);
	if (eventSFML.type == sf::Event::KeyPressed || eventSFML.type == sf::Event::KeyReleased) {
		auto itKeyboard = keyboardMap.find(eventSFML.key.code);
		e.kb_key = (itKeyboard != keyboardMap.end() ? itKeyboard->second : KB_NONE);
	}
	return (true);
}

bool arcade::GfxLapin::doesSupportSound() const {
	return true;
}

void arcade::GfxLapin::tekpixel(t_bunny_pixelarray &pix,
								t_bunny_accurate_position pos,
								unsigned int col) {
	t_color *color;
	
	if ((pos.x * pos.y) < (pix.clipable.clip_width *
						   pix.clipable.clip_height)) {
		color = (t_color *) pix.pixels + (int) pos.x + (int) pos.y * pix.clipable.clip_width;
		color->full = col;
	}
}

void arcade::GfxLapin::drawSquare(t_bunny_accurate_position pos, t_bunny_accurate_position size, u_int32_t color) {
	t_bunny_accurate_position tmpPos;
	
	
	tmpPos.x = pos.x;
	while (tmpPos.x < pos.x + size.x) {
		tmpPos.y = pos.y;
		while (tmpPos.y < pos.y + size.y) {
			tmpPos.y++;
			tekpixel(*pixelarray, tmpPos, color);
		}
		tmpPos.x++;
	}
}

t_color arcade::GfxLapin::convertArcadeColorIntoLapinColor(arcade::Color c) {
	t_color color;
	color.argb[ALPHA_CMP] = c.a;
	color.argb[RED_CMP] = c.r;
	color.argb[GREEN_CMP] = c.g;
	color.argb[BLUE_CMP] = c.b;
	return (color);
}

void arcade::GfxLapin::updateMap(const arcade::IMap &map) {
	t_bunny_accurate_position pos;
	t_bunny_accurate_position size;
	
	for(size_t i = 0; i < map.getLayerNb(); ++i) {
		for(size_t j = 0; j < map.getHeight(); ++j) {
			for(size_t k = 0; k < map.getWidth(); ++k) {
				arcade::Color c = map.at(i, j, k).getColor();
				
				if (c.full != arcade::Color::Transparent.full) {
					t_color color = convertArcadeColorIntoLapinColor(c);
					pos.x = windowsWidth / map.getWidth() * k;
					pos.y = windowsHeight / map.getHeight() * j;
					size.x = windowsWidth / map.getWidth() - 1;
					size.y = windowsHeight / map.getHeight() - 1;
					drawSquare(pos, size, color.full);
				}
			}
		}
	}
}

void arcade::GfxLapin::display() {
	bunny_blit(&window->buffer, &pixelarray->clipable, 0);
	bunny_display(window);
}

void arcade::GfxLapin::clear() {
	bunny_fill(&window->buffer, BLACK);
	fillPixelarrayWithBlack();
}
void arcade::GfxLapin::loadSounds(const std::vector<std::pair<std::string, arcade::SoundType>> &sounds) {
	for(auto it = sounds.begin(); it < sounds.end(); it++) {
		t_bunny_music *music = bunny_load_music(it->first.c_str());
		if (music)
			sound.push_back(music);
	}
}
void arcade::GfxLapin::soundControl(const arcade::Sound &sound) {
	try {
		bunny_sound_play(&this->sound.at(sound.id)->sound);
	}
	catch (std::out_of_range e) {
		std::cerr << "The sound you tried to play is not correctly indexed" << std::endl;
	}
}
void arcade::GfxLapin::loadSprites(std::vector<std::unique_ptr<arcade::ISprite>> &&sprites) {
	(void) sprites;
}

void arcade::GfxLapin::updateGUI(arcade::IGUI &gui) {
	for(size_t i = 0; i < gui.size(); ++i) {
		t_bunny_position position;
		
		position.x = (int) (windowsWidth * gui.at(i).getX());
		position.y = (int) (windowsHeight * gui.at(i).getY());
		arcade::Color c = gui.at(i).getTextColor();
		tektext(pixelarray, font, &position, gui.at(i).getText().c_str(), convertArcadeColorIntoLapinColor(c).full);
	}
}
void arcade::GfxLapin::fillPixelarrayWithBlack() {
	int i = 0;
	
	while (i < pixelarray->clipable.clip_height * pixelarray->clipable.clip_width) {
		t_color *color;
		
		color = (t_color *) pixelarray->pixels + i;
		color->full = BLACK;
		i++;
	}
}

extern "C" arcade::GfxLapin *getLib() {
	return new arcade::GfxLapin();
}
