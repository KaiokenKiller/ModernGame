//
// Created by aj on 15.05.24.
//

#include "Player.h"

Player::Player() {
    m_name = "Nameless";
	m_defense = 0;
	m_modifiedDefense = m_defense;
	m_armorSet = std::make_unique<equippedArmor>();
	m_maxHealth = 100;
	m_health = m_maxHealth;
	m_attack = 10;
}

Player::Player(std::string name, int maxHealth, int defense, int attack){
    m_name = name;
	m_defense = defense;
	m_modifiedDefense = m_defense;
	m_maxHealth = maxHealth;
	m_health = m_maxHealth;
	m_attack = attack;

	m_armorSet = std::make_unique<equippedArmor>();
}

Player::~Player() = default;


std::shared_ptr<Item> Player::getItem(unsigned id){
	if (id > m_inventory.size()){
		fmt::print("Es gibt kein Item mit der ID {0}\n",id);
		return nullptr;
	}

	return m_inventory[id];
}

void Player::addItem(const std::shared_ptr<Item>& item) {
	m_inventory.emplace_back(item);
}

void Player::showInventory() {
	for (auto element:m_inventory){
		if (element->getQuantity()>0)
			fmt::print("{0}\n",element->getItemName());
	}
}

void Player::equipArmor(const std::shared_ptr<Item>& armor) {
    if (m_armorSet->equip(std::dynamic_pointer_cast<Armor>(armor)))
		updateDefense();
}

void Player::unequipArmor(const std::shared_ptr<Item>& armor) {
	if (m_armorSet->unequip(std::dynamic_pointer_cast<Armor>(armor)))
		updateDefense();
}

void Player::updateDefense() {
	m_modifiedDefense = m_defense;
	m_modifiedDefense += m_armorSet->getArmorDefense();
}

int Player::getModifiedDefense() const {
	return m_modifiedDefense;
}

void Player::info(){
	fmt::print("Name: {0}\nLeben: {1}/{2}\nAngriff: {3}\nVerteidigung: {4}\n",m_name,m_health,m_maxHealth,m_attack,m_modifiedDefense);
}