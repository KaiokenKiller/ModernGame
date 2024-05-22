//
// Created by aj on 22.05.24.
//

#ifndef MODERNGAME_ARMOR_H
#define MODERNGAME_ARMOR_H
#include "Item.h"

enum class Tag;

class Armor : Item{
protected:


    Tag m_tag;
    int armor;


public:

    Armor();
    ~Armor();

    Tag getTag();
    int getArmor();
};


#endif //MODERNGAME_ARMOR_H
