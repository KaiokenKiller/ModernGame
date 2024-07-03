//
// Created by aj on 15.05.24.
//
#include "Enemy.h"

Enemy::Enemy(std::string name, int maxHealth, int defense, int attack){
	m_name = name;
	m_maxHealth = maxHealth;
	m_health = m_maxHealth;
	m_defense = defense;
	m_attack = attack;
}

void Enemy::rewards(std::shared_ptr<Player> player) {
	// randomly choose reqard from lootPool and add it to Players inventory
}