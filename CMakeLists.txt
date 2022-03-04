cmake_minimum_required(VERSION 3.20)
project(inform_main)

set(CMAKE_CXX_STANDARD 14)

set(SFML_STATIC_LIBRARIES FALSE)
set(SFML_DIR "C:/SFML-2.5.1-32-bit/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(inform_main
        Event.h
        FightEvent.cpp
        FightEvent.h
        Item.cpp
        Item.h
        main.cpp
        Monster.cpp
        Monster.h
        Player.cpp
        Player.h
        Wizard.cpp
        Wizard.h)

target_link_libraries(inform_main sfml-graphics sfml-window sfml-system)
