//
// Created by aj on 10.07.24.
//

#include "Weapon.h"

Weapon::Weapon(unsigned int id, const std::string &itemName, unsigned int quantity, Tag tag, int attackValue, bool trueDamage): Item(id,itemName,quantity,tag){
	m_attackValue = attackValue;
	m_trueDamage = trueDamage;
}

void Weapon::modifyAttack(Attack &attack){
	attack.setAttack(attack.getAttack()+m_attackValue);
	if (m_trueDamage)
		attack.setTrueDamage(m_trueDamage);
}

int Weapon::getAttackValue() const {
	return m_attackValue;
}

bool Weapon::isTrueDamage() const {
	return m_trueDamage;
}

void Weapon::setAttackValue(int attack){
	m_attackValue = attack;
}

void Weapon::setTrueDamage(bool trueDamage) {
	m_trueDamage = trueDamage;
}

void Weapon::info() {
	fmt::print("ID: {0} \nName: {1} \nAnzahl: {2} \nAngriff: {3} \nTag: {4} \nEigenschaften: {5}\n\n",m_id,m_itemName,m_quantity,m_attackValue,getTagString(),isTrueDamage() ? "True Damage" : "");
}