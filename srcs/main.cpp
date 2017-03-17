#include <iostream>
#include "../include/DLLoader.hpp"
#include "../arcade_interface/IGfxLib.hpp"
#include "../include/Map.hpp"

int main() {
    DLLoader<arcade::IGfxLib> loader("gfxLibs/lib/lib_arcade_sfml.so");

    arcade::IGfxLib *lib = loader.getInstance("getClone");
    lib->display();
    std::cout << "Hello, World!" << std::endl;
    arcade::Map map(10, 10, 1);
    map[0].getHeight();
    std::cout << map[0][0].size() << std::endl;
    map[0][0][0]->setTypeEv(PLAYER);
    std::cout << map[0][0][0]->getType() << std::endl;
    return 0;
}