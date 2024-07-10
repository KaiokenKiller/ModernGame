//
// Created by aj on 22.05.24.
//

#ifndef MODERNGAME_EQUIPPEDARMOR_H
#define MODERNGAME_EQUIPPEDARMOR_H
#include <memory>
#include "../Items/Armor.h"

class equippedArmor {
protected:
    std::shared_ptr<Armor> m_helmet;
    std::shared_ptr<Armor> m_torso;
    std::shared_ptr<Armor> m_legs;
    std::shared_ptr<Armor> m_gloves;


public:
    equippedArmor();
    ~equippedArmor();

    bool equip(const std::shared_ptr<Armor>& armor);

    bool unequip(const std::shared_ptr<Armor>& armor);

	int getArmorDefense();

    std::shared_ptr<Armor> getHelmet();
    std::shared_ptr<Armor> getTorso();
    std::shared_ptr<Armor> getLegs();
    std::shared_ptr<Armor> getGloves();
};


#endif //MODERNGAME_EQUIPPEDARMOR_H
