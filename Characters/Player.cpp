//
// Created by aj on 15.05.24.
//

#include "Player.h"

Player::Player(const std::string &name, int maxHealth, int defense, int attack){
    m_name = name;
	m_armorSet = std::make_unique<equippedArmor>();
	m_baseDefense = defense;
	m_defense = m_baseDefense;
	m_maxHealth = maxHealth;
	m_health = m_maxHealth;
	m_attack = attack;
	m_equippedWeapon = std::make_shared<Weapon>();
	m_inventory = std::make_unique<Itemlist>();
}

std::shared_ptr<Item> Player::getItem(unsigned id){
	return m_inventory->getItem(id);
}

void Player::addItem(unsigned int id){
	m_inventory->addItem(id);
}

void Player::removeItem(unsigned int id){
	m_inventory->removeItem(id);
}

void Player::showInventory() {
	m_inventory->showInventory();
}

void Player::equipArmor(const std::shared_ptr<Item>& armor) {
	auto temp = std::dynamic_pointer_cast<Armor>(armor);
	if (temp->getId() == m_armorSet->getHelmet()->getId() || temp->getId() == m_armorSet->getTorso()->getId() || temp->getId() == m_armorSet->getLegs()->getId() || temp->getId() == m_armorSet->getGloves()->getId()){
		unequipArmor(armor);
		return;
	}
	if (m_armorSet->equip(temp))
		updateDefense();
}

void Player::unequipArmor(const std::shared_ptr<Item>& armor) {
	if (m_armorSet->unequip(std::dynamic_pointer_cast<Armor>(armor)))
		updateDefense();
}

void Player::updateDefense() {
	m_defense = m_baseDefense;
	m_defense += m_armorSet->getArmorDefense();
}

void Player::equipWeapon(const std::shared_ptr<Item> &weapon) {
	if (m_equippedWeapon == weapon){
		unequipWeapon(weapon);
		return;
	}
	m_equippedWeapon = std::dynamic_pointer_cast<Weapon>(weapon);
}

void Player::unequipWeapon(const std::shared_ptr<Item> &weapon) {
	m_equippedWeapon = std::make_shared<Weapon>();
}

std::shared_ptr<Attack> Player::createAttack() const{
	return std::make_shared<Attack>(m_attack+m_equippedWeapon->getAttackValue(),m_equippedWeapon->isTrueDamage());
}

int Player::getBaseDefense() const {
	return m_baseDefense;
}

void Player::info(){
	fmt::print("Name: {0}\nLeben: {1}/{2}\nAngriff: {3}\nVerteidigung: {4}\nWaffe: {5}\nHelm: {6}\nBrustpanzer: {7}\nHose: {8}\nHandschuhe {9}\n", m_name, m_health, m_maxHealth, m_attack+m_equippedWeapon->getAttackValue(), m_defense,m_equippedWeapon->getItemName(),m_armorSet->getHelmet()->getItemName(),m_armorSet->getTorso()->getItemName(),m_armorSet->getLegs()->getItemName(),m_armorSet->getGloves()->getItemName());
}