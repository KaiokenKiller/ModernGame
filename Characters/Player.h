//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_PLAYER_H
#define MODERNGAME_PLAYER_H
#include "Character.h"
#include "../Misc/equippedArmor.h"

class Player : Character{
protected:
    std::unique_ptr<equippedArmor> m_armorSet;

public:
    Player();
    Player(std::string &name);
    ~Player();

    // equips a piece of armor
    void equip(std::shared_ptr<Item*> armor);
    // dequips a piece of armor
    void unequip(std::shared_ptr<Item*> armor);
};


#endif //MODERNGAME_PLAYER_H
