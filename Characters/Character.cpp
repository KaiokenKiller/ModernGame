//
// Created by aj on 15.05.24.
//

#include "Character.h"

Attack* Character::createAttack() {
	return new Attack(m_attack);
}

bool Character::isAlive() const {
	return m_health > 0;
}

int Character::getHealth() const {
    return m_health;
}

int Character::getMaxHealth() const {
	return m_maxHealth;
}

std::string Character::getName() const {
    return m_name;
}

int Character::getAttack() const {
	return m_attack;
}

int Character::getDefense() const {
	return m_defense;
}

void Character::setHealth(int health) {
    m_health = health;
}

void Character::setMaxHealth(int maxHealth) {
	m_maxHealth = maxHealth;
}

void Character::setName(std::string &name) {
    m_name = name;
}

void Character::setAttack(int attack) {
	m_attack = attack;
}

void Character::setDefense(int defense) {
	m_defense = defense;
}

void Character::info() {
	fmt::print("Name: {0}\nLeben: {1}/{2}\nAngriff: {3}\nVerteidigung: {4}",m_name,m_health,m_maxHealth,m_attack,m_defense);
}