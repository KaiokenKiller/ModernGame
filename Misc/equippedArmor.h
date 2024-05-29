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

    void equipHelmet(std::shared_ptr<Armor> helmet);
    void equipTorso(std::shared_ptr<Armor> torso);
    void equipLegs(std::shared_ptr<Armor> legs);
    void equipGloves(std::shared_ptr<Armor> gloves);

    void unequipHelmet();
    void unequipTorso();
    void unequipLegs();
    void unequipGloves();

    std::shared_ptr<Armor> getHelmet();
    std::shared_ptr<Armor> getTorso();
    std::shared_ptr<Armor> getLegs();
    std::shared_ptr<Armor> getGloves();
};


#endif //MODERNGAME_EQUIPPEDARMOR_H
