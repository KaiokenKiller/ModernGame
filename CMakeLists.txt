cmake_minimum_required(VERSION 3.28)
project(ModernGame)

set(CMAKE_CXX_STANDARD 17)

find_package(
        fmt REQUIRED
)

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
        Items/Armor.h
        Misc/Battle.cpp
        Misc/Battle.h
        Areas/Area.cpp
        Areas/Area.h
        Areas/StarterArea.cpp
        Areas/StarterArea.h
        Areas/BanditArea.cpp
        Areas/BanditArea.h
        Misc/Itemlist.cpp
        Misc/Itemlist.h
        Items/Weapon.cpp
        Items/Weapon.h
        Areas/CaveArea.cpp
        Areas/CaveArea.h
        Bosses/CaveTroll.cpp
        Bosses/CaveTroll.h
        Bosses/Necromancer.cpp
        Bosses/Necromancer.h
        Items/Consumeable.cpp
        Items/Consumeable.h
)

target_link_libraries(
        ModernGame PRIVATE fmt::fmt
)