//
// Created by aj on 22.05.24.
//

#include "equippedArmor.h"

equippedArmor::equippedArmor(){
    m_helmet = std::make_shared<Armor>();
    m_torso = std::make_shared<Armor>();
    m_legs = std::make_shared<Armor>();
    m_gloves = std::make_shared<Armor>();
}
equippedArmor::~equippedArmor() = default;

bool equippedArmor::equip(const std::shared_ptr<Armor>& armor){
	if (armor->getTag() == "helmet"){
		m_helmet = armor;
		return true;
	}
	if (armor->getTag() == "torso"){
		m_torso = armor;
		return true;
	}
	if (armor->getTag() == "legs"){
		m_legs = armor;
		return true;
	}
	if (armor->getTag() == "gloves"){
		m_gloves = armor;
		return true;
	}
	fmt::print("{} ist kein Rüstungsteil.\n",armor->getItemName());
	return false;
}


bool equippedArmor::unequip(const std::shared_ptr<Armor>& armor) {
	if (armor == m_helmet){
		m_helmet = nullptr;
		return true;
	}
	if (armor == m_torso){
		m_torso = nullptr;
		return true;
	}
	if (armor == m_legs){
		m_legs = nullptr;
		return true;
	}
	if (armor == m_gloves){
		m_gloves = nullptr;
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
    return m_helmet;
}

std::shared_ptr<Armor> equippedArmor::getLegs() {
    return m_legs;
}

std::shared_ptr<Armor> equippedArmor::getGloves() {
    return m_gloves;
}