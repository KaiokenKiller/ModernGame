//
// Created by aj on 22.05.24.
//

#include "equippedArmor.h"

equippedArmor::equippedArmor() = default;
equippedArmor::~equippedArmor() = default;

void equippedArmor::equipHelmet(std::shared_ptr<Armor> helmet) {
    if (helmet->getTag() == Armor::Tag::helmet)
        m_helmet = helmet;
}

void equippedArmor::equipTorso(std::shared_ptr<Armor> torso) {
    if (torso->getTag() == Armor::Tag::torso)
        m_torso = torso;
}

void equippedArmor::equipLegs(std::shared_ptr<Armor> legs) {
    if (legs->getTag() == Armor::Tag::legs)
        m_legs = legs;
}

void equippedArmor::equipGloves(std::shared_ptr<Armor> gloves) {
    if (gloves->getTag() == Armor::Tag::gloves)
        m_gloves = gloves;
}

Armor equippedArmor::getHelmet() {
    return m_helmet;
}

Armor equippedArmor::getTorso() {
    return m_helmet;
}

Armor equippedArmor::getLegs() {
    return m_legs;
}

Armor equippedArmor::getGloves() {
    return m_gloves;
}