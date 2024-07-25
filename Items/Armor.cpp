//
// Created by aj on 22.05.24.
//

#include "Armor.h"

#include <utility>


Armor::Armor(unsigned int id,const std::string &itemName, unsigned int quantity, Tag tag, int armorValue): Item(id,itemName,quantity,tag) {
    m_armorValue = armorValue;
}

int Armor::getArmorValue() const {
    return m_armorValue;
}

void Armor::setArmor(int armorValue) {
    m_armorValue = armorValue;
}

void Armor::info() {
    fmt::print("ID: {0} \nName: {1} \nAnzahl: {2} \nVerteidigung: {3} \nTag: {4}\n\n",m_id,m_itemName,m_quantity,m_armorValue,getTagString());
}
