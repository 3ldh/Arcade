//
// Created by sauvau_m on 3/7/17.
//

#ifndef DLOPEN_TEST_DLLOADER_H
#define DLOPEN_TEST_DLLOADER_H

#include <dlfcn.h>
#include "Exception.hpp"

template <typename T>
class DLLoader {
    void *handle;

public:
    DLLoader(std::string const &lib);
    virtual ~DLLoader();
    T *getInstance(std::string const &classEntryPoint);
    void deleteInstance();
};

template <typename T>
DLLoader<T>::DLLoader(std::string const &lib) : handle(dlopen(lib.c_str(), RTLD_NOW)) {
    if (!handle) {
        std::cout << dlerror() << std::endl;
        throw arcade::DLLoaderError("DLLloader : Can't load " + lib);
    }
}

template <typename T>
DLLoader<T>::~DLLoader() {
    dlclose(handle);
}

template <typename T>
T *DLLoader<T>::getInstance(std::string const &classEntryPoint) {
    T *(*create)();

    create = (T *(*)(void))dlsym(handle, classEntryPoint.c_str());
    return create();
}


#endif //DLOPEN_TEST_DLLOADER_H
