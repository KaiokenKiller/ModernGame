//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ADVENTURE_H
#define MODERNGAME_ADVENTURE_H
#include "Characters/Player.h"
#include "Characters/Enemy.h"
#include "Items/Item.h"
#include "Items/Armor.h"
#

class Adventure {
private:
    Player player;


public:
    Adventure();

    ~Adventure();

    void start();
    void test();
};


#endif //MODERNGAME_ADVENTURE_H
