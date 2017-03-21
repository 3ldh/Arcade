cmake_minimum_required(VERSION 3.6)
project(cpp_arcade)

set(CMAKE_CXX_STANDARD 11)

include_directories("./gfxLibsSrcs/lapin")

file(GLOB INTERFACES "ArcadeInterfaces/*.hpp"
                     "ArcadeInterfaces/*.cpp")

file(GLOB GAMES "gamesSrcs/snake/*.cpp"
                "gamesSrcs/snake/*.hpp")

file(GLOB_RECURSE GFX_LIBS "gfxLibsSrcs/*.hpp"
                           "gfxLibsSrcs/*.cpp")

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
