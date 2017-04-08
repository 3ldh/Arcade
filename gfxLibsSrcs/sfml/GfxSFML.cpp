//
// Created by sauvau_m on 3/17/17.
//

#include <SFML/Window.hpp>
#include <iostream>
#include "GfxSFML.hpp"
#include "../../include/Exception.hpp"

arcade::GfxSFML::~GfxSFML() {
    window.close();
}

arcade::GfxSFML::GfxSFML() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Arcade - SFML", sf::Style::Close | sf::Style::Titlebar,
                  settings);
    window.setMouseCursorVisible(false);

    eventsKeyboard[sf::Keyboard::Key::A] = KB_A; /// A key
    eventsKeyboard[sf::Keyboard::Key::B] = KB_B; /// B key
    eventsKeyboard[sf::Keyboard::Key::C] = KB_C; /// C key
    eventsKeyboard[sf::Keyboard::Key::D] = KB_D; /// D key
    eventsKeyboard[sf::Keyboard::Key::E] = KB_E; /// E key
    eventsKeyboard[sf::Keyboard::Key::F] = KB_F; /// F key
    eventsKeyboard[sf::Keyboard::Key::G] = KB_G; /// G key
    eventsKeyboard[sf::Keyboard::Key::H] = KB_H; /// H key
    eventsKeyboard[sf::Keyboard::Key::I] = KB_I; /// I key
    eventsKeyboard[sf::Keyboard::Key::J] = KB_J; /// J key
    eventsKeyboard[sf::Keyboard::Key::K] = KB_K; /// K key
    eventsKeyboard[sf::Keyboard::Key::L] = KB_L; /// L key
    eventsKeyboard[sf::Keyboard::Key::M] = KB_M; /// M key
    eventsKeyboard[sf::Keyboard::Key::N] = KB_N; /// N key
    eventsKeyboard[sf::Keyboard::Key::O] = KB_O; /// O key
    eventsKeyboard[sf::Keyboard::Key::P] = KB_P; /// P key
    eventsKeyboard[sf::Keyboard::Key::Q] = KB_Q; /// Q key
    eventsKeyboard[sf::Keyboard::Key::R] = KB_R; /// R key
    eventsKeyboard[sf::Keyboard::Key::S] = KB_S; /// S key
    eventsKeyboard[sf::Keyboard::Key::T] = KB_T; /// T key
    eventsKeyboard[sf::Keyboard::Key::U] = KB_U; /// U key
    eventsKeyboard[sf::Keyboard::Key::V] = KB_V; /// V key
    eventsKeyboard[sf::Keyboard::Key::X] = KB_X; /// X key
    eventsKeyboard[sf::Keyboard::Key::Y] = KB_Y; /// Y key
    eventsKeyboard[sf::Keyboard::Key::Z] = KB_Z; /// Z key
    eventsKeyboard[sf::Keyboard::Key::Num0] = KB_0; /// 0 key
    eventsKeyboard[sf::Keyboard::Key::Num1] = KB_1; /// 1 key
    eventsKeyboard[sf::Keyboard::Key::Num2] = KB_2; /// 2 key
    eventsKeyboard[sf::Keyboard::Key::Num3] = KB_3; /// 3 key
    eventsKeyboard[sf::Keyboard::Key::Num4] = KB_4; /// 4 key
    eventsKeyboard[sf::Keyboard::Key::Num5] = KB_5; /// 5 key
    eventsKeyboard[sf::Keyboard::Key::Num6] = KB_6; /// 6 key
    eventsKeyboard[sf::Keyboard::Key::Num7] = KB_7; /// 7 key
    eventsKeyboard[sf::Keyboard::Key::Num8] = KB_8; /// 8 key
    eventsKeyboard[sf::Keyboard::Key::Num9] = KB_9; /// 9 key
    eventsKeyboard[sf::Keyboard::Key::Left] = KB_ARROW_LEFT; /// Left arrow key
    eventsKeyboard[sf::Keyboard::Key::Right] = KB_ARROW_RIGHT;/// Right arrow key
    eventsKeyboard[sf::Keyboard::Key::Up] = KB_ARROW_UP; /// Up arrow key
    eventsKeyboard[sf::Keyboard::Key::Down] = KB_ARROW_DOWN; /// Down arrow key
    eventsKeyboard[sf::Keyboard::Key::Space] = KB_SPACE; /// Space key
    eventsKeyboard[sf::Keyboard::Key::Return] = KB_ENTER; /// Enter/Carriage return key
    eventsKeyboard[sf::Keyboard::Key::BackSpace] = KB_BACKSPACE; /// Backspace key
    eventsKeyboard[sf::Keyboard::Key::LControl] = KB_LCTRL; /// Left Control key
    eventsKeyboard[sf::Keyboard::Key::RControl] = KB_RCTRL; /// Right Control key
    eventsKeyboard[sf::Keyboard::Key::LAlt] = KB_LALT; /// Left Alt key
    eventsKeyboard[sf::Keyboard::Key::RAlt] = KB_RALT; /// Right Alt key
    eventsKeyboard[sf::Keyboard::Key::LShift] = KB_LSHIFT; /// Left Shift key
    eventsKeyboard[sf::Keyboard::Key::RShift] = KB_RSHIFT; /// Right Shift key
    eventsKeyboard[sf::Keyboard::Key::Tab] = KB_TAB; /// Tabulation key
    eventsKeyboard[sf::Keyboard::Key::Escape] = KB_ESCAPE; /// Escape key
    eventsKeyboard[sf::Keyboard::Key::PageUp] = KB_PAGEUP; /// Page up key
    eventsKeyboard[sf::Keyboard::Key::PageDown] = KB_PAGEDOWN; /// Page down
    eventsKeyboard[sf::Keyboard::Key::Home] = KB_HOME; /// Home key
    eventsKeyboard[sf::Keyboard::Key::End] = KB_END; /// End key
    eventsKeyboard[sf::Keyboard::Key::F1] = KB_FN1; /// Function key 1 (F1)
    eventsKeyboard[sf::Keyboard::Key::F2] = KB_FN2; /// Function key 2 (F2)
    eventsKeyboard[sf::Keyboard::Key::F3] = KB_FN3; /// Function key 3 (F3)
    eventsKeyboard[sf::Keyboard::Key::F4] = KB_FN4; /// Function key 4 (F4)
    eventsKeyboard[sf::Keyboard::Key::F5] = KB_FN5; /// Function key 5 (F5)
    eventsKeyboard[sf::Keyboard::Key::F6] = KB_FN6; /// Function key 6 (F6)
    eventsKeyboard[sf::Keyboard::Key::F7] = KB_FN7; /// Function key 7 (F7)
    eventsKeyboard[sf::Keyboard::Key::F8] = KB_FN8; /// Function key 8 (F8)
    eventsKeyboard[sf::Keyboard::Key::F9] = KB_FN9; /// Function key 9 (F9)
    eventsKeyboard[sf::Keyboard::Key::F10] = KB_FN10; /// Function key 10 (F10)
    eventsKeyboard[sf::Keyboard::Key::F11] = KB_FN11; /// Function key 11 (F11)
    eventsKeyboard[sf::Keyboard::Key::F12] = KB_FN12; /// Function key 12 (F12)
    eventsKeyboard[sf::Keyboard::Key::Comma] = KB_COMMA; /// Comma key (,)
    eventsKeyboard[sf::Keyboard::Key::Period] = KB_DOT; /// Dot (period) key (.)
    eventsKeyboard[sf::Keyboard::Key::Slash] = KB_SLASH; /// Slash key (/)
    eventsKeyboard[sf::Keyboard::Key::SemiColon] = KB_SEMICOLON; /// Semicolon key (;)
    eventsKeyboard[sf::Keyboard::Key::Quote] = KB_SIMPLEQUOTE; /// Simple quote key (')
    eventsKeyboard[sf::Keyboard::Key::LBracket] = KB_LEFTBRACKET; /// Left bracket key ([)
    eventsKeyboard[sf::Keyboard::Key::RBracket] = KB_RIGHTBRACKET;/// Right bracker key (])
    eventsKeyboard[sf::Keyboard::Key::BackSlash] = KB_BACKSLASH; /// Backslash key (\)
    eventsKeyboard[sf::Keyboard::Key::Multiply] = KB_ASTERISK; /// Asterisk key (*)
    eventsKeyboard[sf::Keyboard::Key::Subtract] = KB_MINUS; /// Minus symbol key (-)
    eventsKeyboard[sf::Keyboard::Key::Add] = KB_PLUS; /// Plus symbol key (+)
    eventsKeyboard[sf::Keyboard::Key::Equal] = KB_EQUALS;
    eventsKeyboard[sf::Keyboard::Key::Delete] = KB_DELETE;

    eventsActionType[sf::Event::KeyPressed] = AT_PRESSED;
    eventsActionType[sf::Event::KeyReleased] = AT_RELEASED;

    eventsType[sf::Event::Closed] = ET_QUIT;
    eventsType[sf::Event::KeyPressed] = ET_KEYBOARD;
    eventsType[sf::Event::KeyReleased] = ET_KEYBOARD;

}


bool arcade::GfxSFML::pollEvent(arcade::Event &e) {

    sf::Event eventSFML;
    bool event = window.pollEvent(eventSFML);
    if (!event)
        return (false);
    auto it_et = eventsType.find(eventSFML.type);
    it_et != eventsType.end() ? e.type = (*it_et).second : e.type = ET_NONE;
    auto it_eat = eventsActionType.find(eventSFML.type);
    it_eat != eventsActionType.end() ? e.action = (*it_eat).second : e.action = AT_NONE;
    if (eventSFML.type == sf::Event::KeyPressed || eventSFML.type == sf::Event::KeyReleased) {
        auto it = eventsKeyboard.find(eventSFML.key.code);
        it != eventsKeyboard.end() ? e.kb_key = (*it).second : e.kb_key = KB_NONE;
    }
    return (true);
}

bool arcade::GfxSFML::doesSupportSound() const {
    return false;
}

void arcade::GfxSFML::updateMap(const arcade::IMap &map) {
    for (size_t i = 0; i < map.getLayerNb(); ++i) {
        for (size_t j = 0; j < map.getHeight(); ++j) {
            for (size_t k = 0; k < map.getWidth(); ++k) {
                if (map.at(i, j, k).hasSprite()) {

                } else {
                    arcade::Color c = map.at(i, j, k).getColor();
/*
                        sf::CircleShape circle(WIN_WIDTH / map.getWidth() / 2);
                        circle.setFillColor(sf::Color(c.rgba[0], c.rgba[1], c.rgba[2]));
                        circle.setPosition(WIN_WIDTH / map.getWidth() * k, WIN_HEIGHT / map.getHeight() * j);
                        window.draw(circle);
*/

                        sf::RectangleShape rectangle(
                                sf::Vector2f(WIN_WIDTH / map.getWidth(), WIN_HEIGHT / map.getHeight()));
                        rectangle.setPosition(WIN_WIDTH / map.getWidth() * k, WIN_HEIGHT / map.getHeight() * j);
                        rectangle.setFillColor(sf::Color(c.rgba[0], c.rgba[1], c.rgba[2], c.rgba[3]));
                        rectangle.setOutlineColor(sf::Color(sf::Color::Black));
                        rectangle.setOutlineThickness(1);
                        window.draw(rectangle);
                }
            }
        }
    }
}

void arcade::GfxSFML::display() {
    window.display();
}

void arcade::GfxSFML::clear() {
    window.clear();
}

void arcade::GfxSFML::loadSounds(const std::vector<std::pair<std::string, arcade::SoundType>> &sounds) {

}

void arcade::GfxSFML::soundControl(const arcade::Sound &sound) {

}

void arcade::GfxSFML::loadSprites(std::vector<std::unique_ptr<arcade::ISprite>> &&sprites) {

}

void arcade::GfxSFML::updateGUI(arcade::IGUI &gui) {
    for (size_t i = 0; i < gui.size(); ++i) {
        arcade::Color c = gui.at(i).getTextColor();
        sf::Font font;
        if (!font.loadFromFile("./gfxLibsSrcs/mytype.ttf"))
            throw GfxLibError("GfxLibError : Font file not found");
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(16);
        text.setString(gui.at(i).getText());
        text.setPosition((int) gui.at(i).getX(), (int) gui.at(i).getY());
        text.setColor(sf::Color(c.rgba[0], c.rgba[1], c.rgba[2]));
        window.draw(text);
    }
}

extern "C" arcade::GfxSFML *getLib() {
    return new arcade::GfxSFML();
}
