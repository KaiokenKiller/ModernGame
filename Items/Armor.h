//
// Created by aj on 22.05.24.
//

#ifndef MODERNGAME_ARMOR_H
#define MODERNGAME_ARMOR_H
#include "Item.h"

class Armor : public Item{
protected:

    int m_armorValue;


public:

    Armor();

    Armor(unsigned id, std::string itemName, unsigned quantity, std::string tag, int armorValue);

    ~Armor();


    int getArmorValue();


    void setArmor(int armorValue);

    void info() override;
};


#endif //MODERNGAME_ARMOR_H
