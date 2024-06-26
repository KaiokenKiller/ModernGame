//
// Created by aj on 15.05.24.
//

#include "Player.h"

Player::Player() {
    m_name = "Nameless";
	m_modifiedDefense = getDefense();
	m_armorSet = std::make_unique<equippedArmor>();
}

Player::Player(std::string name){
    m_name = name;
	m_modifiedDefense = getDefense();
	m_armorSet = std::make_unique<equippedArmor>();
}

Player::~Player() = default;


std::shared_ptr<Item> Player::getItem(unsigned id){
	if (id > m_inventory.size()){
		fmt::print("Es gibt kein Item mit der ID {}\n",id);
		return nullptr;
	}

	return m_inventory[id];
}

void Player::addItem(const std::shared_ptr<Item>& item) {
	m_inventory.emplace_back(item);
}


void Player::equipArmor(const std::shared_ptr<Item>& armor) {
    m_armorSet->equip(std::dynamic_pointer_cast<Armor>(armor));

}

void Player::unequipArmor(const std::shared_ptr<Item>& armor) {
	m_armorSet->unequip(std::dynamic_pointer_cast<Armor>(armor));
}

void Player::updateDefense() {
	m_modifiedDefense = m_defense;
	m_modifiedDefense += m_armorSet->getArmorDefense();
}

int Player::getModifiedDefense() const {
	return m_modifiedDefense;
}

void Player::info(){
	fmt::print("Name: {0}\nHealth: {1}/{2}\nAttack: {3}\nDefense: {4}\n",m_name,m_health,m_maxHealth,m_attack,m_modifiedDefense);
}