//
// Created by aj on 15.05.24.
//
#include "Enemy.h"

#include <utility>

Enemy::Enemy(const std::string &name, int maxHealth, int defense, int attack){
	m_name = name;
	m_maxHealth = maxHealth;
	m_health = m_maxHealth;
	m_defense = defense;
	m_attack = attack;
}

void Enemy::rewards(const std::shared_ptr<Player> &player ) {
	// randomly choose reqard from lootPool and add it to Players inventory
}