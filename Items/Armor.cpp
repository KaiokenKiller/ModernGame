//
// Created by aj on 22.05.24.
//

#include "Armor.h"

Armor::Armor() = default;

Armor::Armor(unsigned int id, std::string itemName, unsigned int quantity, std::string tag, int armorValue) {
    Item(id,itemName,quantity);
    m_tag = tag;
    m_armorValue = armorValue;
}

Armor::~Armor() = default;

std::string Armor::getTag() {
    return m_tag;
}

int Armor::getArmor() {
    return m_armorValue;
}

void Armor::setArmor(int armorValue) {
    m_armorValue = armorValue;
}

void Armor::setTag(std::string tag) {
    m_tag = tag;
}

void Armor::info() {
    std::cout << "Defense: " << m_armorValue << "\n Tag: " << m_tag << std::endl;
}
