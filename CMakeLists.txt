cmake_minimum_required(VERSION 3.20)
project(inform_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

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
