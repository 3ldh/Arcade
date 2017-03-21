//
// Created by peau_c on 3/20/17.
//

#include "../include/GfxLapin.hpp"

bool arcade::GfxLapin::pollEvent(arcade::Event &e) {
	return false;
}

bool arcade::GfxLapin::doesSupportSound() const {
	return true;
}

void arcade::GfxLapin::loadSounds(std::vector<std::string> const &sounds) {
	
}

void arcade::GfxLapin::playSound(int soundId) {
	
}

void arcade::GfxLapin::setSize(size_t height, size_t width) {
	windowsHeight = height;
	windowsWidth = width;
}

void arcade::GfxLapin::setPosition(size_t y, size_t x) {
	
}

void arcade::GfxLapin::initializeWindow() {
	
}

void arcade::GfxLapin::updateMap(const arcade::IMap &map) {
	
}

void arcade::GfxLapin::updateGUI(const arcade::IGUI &gui) {
	
}

void arcade::GfxLapin::display() {
	
}

void arcade::GfxLapin::clear() {
	
}

arcade::GfxLapin::~GfxLapin() {
	initializeWindow();
	
}

arcade::GfxLapin::GfxLapin() {
	
}

extern "C" arcade::GfxLapin *getClone() {
	return new arcade::GfxLapin();
}
