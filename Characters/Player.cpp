//
// Created by aj on 15.05.24.
//

#include "Player.h"

Player::Player() {
    m_name = "Nameless";
}

Player::Player(std::string &name) {
    m_name = name;
}

Player::~Player() = default;

void Player::equip(std::shared_ptr<Item*> armor) {
    if ((*armor)->getTag() == "helmet") {
        m_armorSet->equipHelmet(armor);
        return;
    }
    if ((*armor)->getTag() == "torso") {
        m_armorSet->equipTorso(armor);
        return;
    }
    if (armor->getTag() == "legs") {
        m_armorSet->equipLegs(armor);
        return;
    }
    if (armor->getTag() == "gloves") {
        m_armorSet->equipGloves(armor);
        return;
    }
    fmt::print("{} ist kein Rüstungsteil.\n",armor->getItemName());
}

void Player::unequip(std::shared_ptr<Item*> armor) {
    if (armor->getTag() == "helmet") {
        if (armor == m_armorSet->getHelmet())
            m_armorSet->unequipHelmet();
        else
            fmt::print("{} ist nicht ausgerüstet.")
        return;
    }
    if (armor->getTag() == "torso") {
        if (armor == m_armorSet->getTorso())
            m_armorSet->unequipTorso();
        else
            fmt::print("{} ist nicht ausgerüstet.")
        return;
    }
    if (armor->getTag() == "legs") {
        if (armor == m_armorSet->getLegs())
            m_armorSet->unequipLegs();
        else
            fmt::print("{} ist nicht ausgerüstet.")
        return;
    }
    if (armor->getTag() == "gloves") {
        if (armor == m_armorSet->getGloves())
            m_armorSet->unequipGloves();
        else
            fmt::print("{} ist nicht ausgerüstet.")
        return;
    }
    fmt::print("{} ist kein Rüstungsteil.\n",armor->getItemName());
}