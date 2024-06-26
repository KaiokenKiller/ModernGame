//
// Created by aj on 22.05.24.
//

#include "Armor.h"

Armor::Armor(){
	m_id = 0;
	m_itemName = "Leer";
	m_quantity = 0;
	m_tag = "Leer";
	m_armorValue = 0;
}

Armor::Armor(unsigned int id, std::string itemName, unsigned int quantity, std::string tag, int armorValue) {
    m_id = id;
    m_itemName = itemName;
    m_quantity = quantity;
    m_tag = tag;
    m_armorValue = armorValue;
}

Armor::~Armor() = default;

int Armor::getArmorValue() {
    return m_armorValue;
}

void Armor::setArmor(int armorValue) {
    m_armorValue = armorValue;
}

void Armor::info() {
    fmt::print("ID: {0} \nName: {1} \nAnzahl: {2} \nDefense: {3} \nTag: {4}\n",m_id,m_itemName,m_quantity,m_armorValue,m_tag);
}
