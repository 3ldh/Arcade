cmake_minimum_required(VERSION 3.6)
project(cpp_arcade)

set(CMAKE_CXX_STANDARD 11)

file(GLOB INTERFACES "ArcadeInterfaces/*.hpp")

file(GLOB GAMES "games/snake/*.cpp"
                "games/snake/*.hpp")

file(GLOB GFX_LIBS "gfxLibs/sfml/*.hpp"
                    "gfxLibs/sfml/*.cpp")

file(GLOB INCLUDE_FILES "include/*.hpp")

file(GLOB SOURCE_FILES "srcs/*.cpp")

add_executable(cpp_arcade ${INTERFACES} ${GAMES} ${INCLUDE_FILES} ${GFX_LIBS} ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#[[
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(cpp_arcade ${SFML_LIBRARIES})
endif()]]
