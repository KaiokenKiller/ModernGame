//
// Created by aj on 22.05.24.
//

#include "Armor.h"

Armor::Armor() = default;

Armor::Armor(unsigned int id, std::string itemName, unsigned int quantity, std::string tag, int armorValue) {
    m_id = id;
    m_itemName = itemName;
    m_quantity = quantity;
    m_tag = tag;
    m_armorValue = armorValue;
}

Armor::~Armor() = default;

int Armor::getArmor() {
    return m_armorValue;
}

void Armor::setArmor(int armorValue) {
    m_armorValue = armorValue;
}

void Armor::info() {
    fmt::print("ID: {0} \nName: {1} \nAnzahl: {2} \nDefense: {3} \nTag: {4}",m_id,m_itemName,m_quantity,m_armorValue,m_tag);
}
