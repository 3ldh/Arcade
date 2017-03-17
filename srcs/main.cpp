#include <iostream>
#include "../include/DLLoader.hpp"
#include "../arcade_interface/IGfxLib.hpp"

int main() {
    DLLoader<arcade::IGfxLib> loader("gfxLibs/lib/lib_arcade_sfml.so");

    arcade::IGfxLib *lib = loader.getInstance("getClone");
    lib->display();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}