//
// Created by aj on 22.05.24.
//

#include "equippedArmor.h"

const std::shared_ptr<Armor> equippedArmor::m_emptyHelmet = std::make_shared<Armor>(0,"Leer",0,Tag::helmet,0);
const std::shared_ptr<Armor> equippedArmor::m_emptyTorso = std::make_shared<Armor>(0,"Leer",0,Tag::helmet,0);
const std::shared_ptr<Armor> equippedArmor::m_emptyLegs = std::make_shared<Armor>(0,"Leer",0,Tag::helmet,0);
const std::shared_ptr<Armor> equippedArmor::m_emptyGloves = std::make_shared<Armor>(0,"Leer",0,Tag::helmet,0);

equippedArmor::equippedArmor(){
    m_helmet = m_emptyHelmet;
    m_torso = m_emptyTorso;
    m_legs = m_emptyLegs;
    m_gloves = m_emptyGloves;
}

bool equippedArmor::equip(const std::shared_ptr<Armor>& armor){
	switch (armor->getTag()) {
		case Tag::helmet: {
			m_helmet = armor;
			return true;
		}
		case Tag::torso: {
			m_torso = armor;
			return true;
		}
		case Tag::legs: {
			m_legs = armor;
			return true;
		}
		case Tag::gloves: {
			m_gloves = armor;
			return true;
		}
		default: {
			fmt::print("{} ist kein Rüstungsteil.\n", armor->getItemName());
			return false;
		}
	}
}


bool equippedArmor::unequip(const std::shared_ptr<Armor>& armor) {
	if (armor == m_helmet){
		m_helmet = m_emptyHelmet;
		return true;
	}
	if (armor == m_torso){
		m_torso = m_emptyTorso;
		return true;
	}
	if (armor == m_legs){
		m_legs = m_emptyLegs;
		return true;
	}
	if (armor == m_gloves){
		m_gloves = m_emptyGloves;
		return true;
	}
	fmt::print("{} ist nicht ausgerüstet.\n",armor->getItemName());
	return false;
}


int equippedArmor::getArmorDefense() {
	int def = 0;
	if (m_helmet != nullptr)
		def += m_helmet->getArmorValue();
	if (m_torso != nullptr)
		def += m_torso->getArmorValue();
	if (m_legs != nullptr)
		def += m_legs->getArmorValue();
	if (m_gloves != nullptr)
		def += m_gloves->getArmorValue();
	return def;
}


std::shared_ptr<Armor> equippedArmor::getHelmet() {
    return m_helmet;
}

std::shared_ptr<Armor> equippedArmor::getTorso() {
    return m_torso;
}

std::shared_ptr<Armor> equippedArmor::getLegs() {
    return m_legs;
}

std::shared_ptr<Armor> equippedArmor::getGloves() {
    return m_gloves;
}