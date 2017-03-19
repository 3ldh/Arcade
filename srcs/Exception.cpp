//
// Created by sauvau_m on 3/19/17.
//

#include "../include/Exception.hpp"

arcade::ArcadeError::~ArcadeError() throw() {

}

arcade::ArcadeError::ArcadeError(std::string const &msg) throw() : msg(msg)  {

}

const char *arcade::ArcadeError::what() const throw() {
    return msg.c_str();
}

arcade::GfxLibError::~GfxLibError() throw() {

}

arcade::GfxLibError::GfxLibError(const std::string &msg) throw() : ArcadeError(msg) {}

arcade::GameLibError::~GameLibError() throw() {

}

arcade::GameLibError::GameLibError(const std::string &msg) throw() : ArcadeError(msg) {

}

arcade::DLLoaderError::~DLLoaderError() throw() {

}

arcade::DLLoaderError::DLLoaderError(const std::string &msg) throw() : ArcadeError(msg) {

}
