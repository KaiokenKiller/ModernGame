cmake_minimum_required(VERSION 3.28)
project(ModernGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(ModernGame main.cpp
        Adventure.cpp
        Adventure.h
        Characters/Character.cpp
        Characters/Character.h
        Characters/Player.cpp
        Characters/Player.h
        Characters/Enemy.cpp
        Characters/Enemy.h
        Items/Item.cpp
        Items/Item.h
        Misc/Attack.cpp
        Misc/Attack.h
        Misc/equippedArmor.cpp
        Misc/equippedArmor.h
        Items/Armor.cpp
        Items/Armor.h)
