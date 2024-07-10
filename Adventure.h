//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ADVENTURE_H
#define MODERNGAME_ADVENTURE_H
#include "Characters/Player.h"
#include "Characters/Enemy.h"
#include "Items/Item.h"
#include "Items/Armor.h"
#include "Misc/Battle.h"
#include "Areas/StarterArea.h"
#include <chrono>
#include <thread>

class Adventure {
private:
    std::shared_ptr<Player> m_player;


public:
    Adventure();

    ~Adventure();

    void start();
    void test();
};


#endif //MODERNGAME_ADVENTURE_H
