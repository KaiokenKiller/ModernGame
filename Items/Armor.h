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
	// valid Armor tags are helmet, torso, legs, gloves
    Armor(unsigned id,const std::string &itemName, unsigned quantity, std::string tag, int armorValue);

    ~Armor();
    [[nodiscard]] int getArmorValue() const;
    void setArmor(int armorValue);

    void info() override;
};


#endif //MODERNGAME_ARMOR_H
