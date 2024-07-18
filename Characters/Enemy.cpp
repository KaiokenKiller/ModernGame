//
// Created by aj on 15.05.24.
//
#include "Enemy.h"

#include <utility>

Enemy::Enemy(const std::string &name, int maxHealth, int defense, int attack, const std::vector<unsigned>& lootPool){
	m_name = name;
	m_maxHealth = maxHealth;
	m_health = m_maxHealth;
	m_defense = defense;
	m_attack = attack;
	m_lootPool = lootPool;
}

void Enemy::rewards(const std::shared_ptr<Player> &player ) {
	// randomly choose reqard from lootPool and add it to Players inventory
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> loot(0,m_lootPool.size()-1);
	int rngLoot = loot(gen);
	player->addItem(m_lootPool[rngLoot]);
}