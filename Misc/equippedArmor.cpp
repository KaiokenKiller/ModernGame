//
// Created by aj on 22.05.24.
//

#include "equippedArmor.h"

equippedArmor::equippedArmor(){
    m_helmet = nullptr;
    m_torso = nullptr;
    m_legs = nullptr;
    m_gloves = nullptr;
}
equippedArmor::~equippedArmor() = default;

void equippedArmor::equipHelmet(std::shared_ptr<Armor> helmet) {
    if (helmet->getTag() == "helmet")
        m_helmet = helmet;
}

void equippedArmor::equipTorso(std::shared_ptr<Armor> torso) {
    if (torso->getTag() == "torso")
        m_torso = torso;
}

void equippedArmor::equipLegs(std::shared_ptr<Armor> legs) {
    if (legs->getTag() == "legs")
        m_legs = legs;
}

void equippedArmor::equipGloves(std::shared_ptr<Armor> gloves) {
    if (gloves->getTag() == "gloves")
        m_gloves = gloves;
}


void equippedArmor::unequipHelmet() {
    m_helmet = nullptr;
}

void equippedArmor::unequipTorso() {
    m_torso = nullptr;
}

void  equippedArmor::unequipLegs() {
    m_legs = nullptr;
}

void equippedArmor::unequipGloves() {
    m_gloves = nullptr;
}



std::shared_ptr<Armor> equippedArmor::getHelmet() {
    return m_helmet;
}

std::shared_ptr<Armor> equippedArmor::getTorso() {
    return m_helmet;
}

std::shared_ptr<Armor> equippedArmor::getLegs() {
    return m_legs;
}

std::shared_ptr<Armor> equippedArmor::getGloves() {
    return m_gloves;
}