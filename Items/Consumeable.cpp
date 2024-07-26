//
// Created by aj on 26.07.24.
//

#include "Consumeable.h"

Consumeable::Consumeable(unsigned int id, const std::string &itemName, unsigned int quantity, Tag tag, int modifyValue, double modifyMultiplier): Item(id,itemName,quantity,tag) {
	m_modifyValue = modifyValue;
	m_modifyMultiplier = modifyMultiplier;
}

int Consumeable::healing(int health) const {
	health += m_modifyValue;
	health *= m_modifyMultiplier;
	return health;
}

std::shared_ptr<Attack> Consumeable::throwable() const {
	return std::make_shared<Attack>(m_modifyValue*m_modifyMultiplier,true);
}

std::shared_ptr<Attack> Consumeable::buffDamage(std::shared_ptr<Attack> attack) const {
	attack->setAttack((attack->getAttack()+m_modifyValue)*m_modifyMultiplier);
	return attack;
}

void Consumeable::info() {
	fmt::print("ID: {0} \nName: {1} \nAnzahl: {2} \n{3}: {4} \nTag: {5}\n\n",m_id,m_itemName,m_quantity,(m_tag == Tag::healing)?"Heilung":
		(m_tag == Tag::throwable)?"Schaden":
		(m_tag == Tag::buffDamage)?"Extraschaden":
		"",(m_modifyValue == 0)?std::to_string(m_modifyMultiplier) + "x":std::to_string(static_cast<int>(m_modifyMultiplier*m_modifyValue)),getTagString());
}
