//
// Created by sauvau_m on 3/19/17.
//

#ifndef CPP_ARCADE_EXCEPTION_HPP
#define CPP_ARCADE_EXCEPTION_HPP

#include <string>
#include <exception>

namespace arcade {

    class ArcadeError: public std::exception {
        std::string msg;
        ArcadeError() throw();

    public:
        virtual ~ArcadeError() throw();
        ArcadeError(std::string const &msg) throw();
        virtual const char *what() const throw();
    };

    class DLLoaderError: public ArcadeError {
    public:
        virtual ~DLLoaderError() throw();
        DLLoaderError(const std::string &msg) throw();
    };

    class GfxLibError: public ArcadeError {
    public:
        virtual ~GfxLibError() throw();
        GfxLibError(const std::string &msg) throw();
    };

    class GameLibError: public ArcadeError {
    public:
        virtual ~GameLibError() throw();
        GameLibError(const std::string &msg) throw();
    };
}


#endif //CPP_ARCADE_EXCEPTION_HPP
