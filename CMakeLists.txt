cmake_minimum_required(VERSION 3.29)
project(CS225GroupProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS225GroupProject
        Character.cpp
        Character.h
        Dungeon.cpp
        Dungeon.h
        Enemy.cpp
        Enemy.h
        main.cpp
        Npc.cpp
        Npc.h
        Player.cpp
        Player.h
        Spells.cpp
        Spells.h
        Weapon.cpp
        Weapon.h)
