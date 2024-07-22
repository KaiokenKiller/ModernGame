//
// Created by aj on 10.07.24.
//

#include "BanditArea.h"

BanditArea::BanditArea(const std::string &areaname, unsigned minEnemyCount, unsigned maxEnemyCount){
	m_areaname = areaname;
	m_enemyTypeCount = 4;
	m_minEnemyCount = minEnemyCount;
	m_maxEnemyCount = maxEnemyCount;
}

//randomly generate Vector of enemies from the Area and return it
std::vector<std::shared_ptr<Enemy>>& BanditArea::generateEnemies() {
	auto generatedEnemies = new std::vector<std::shared_ptr<Enemy>>();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disCount(static_cast<int>(m_minEnemyCount), static_cast<int>(m_maxEnemyCount));
	std::uniform_int_distribution<> disType(0, static_cast<int>(m_enemyTypeCount) - 1);
	int rngEnemyCount = disCount(gen);

	for (int i = 0; i < rngEnemyCount; ++i) {

		int rngEnemyType = disType(gen);

		switch (rngEnemyType) {
			case 0: {
				std::vector<unsigned> loot;
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(2);
				loot.emplace_back(3);
				loot.emplace_back(4);
				loot.emplace_back(5);
				loot.emplace_back(6);
				loot.emplace_back(12);
				loot.emplace_back(12);

				auto bandit = std::make_shared<Enemy>("Bandit", 20, 3, 5, loot);
				generatedEnemies->emplace_back(bandit);
				break;
			}
			case 1: {
				std::vector<unsigned> loot;
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(3);
				loot.emplace_back(4);
				loot.emplace_back(5);
				loot.emplace_back(6);
				loot.emplace_back(12);
				loot.emplace_back(13);

				auto banditArcher = std::make_shared<Enemy>("Banditen Bogenschütze", 20, 0, 10, loot);
				generatedEnemies->emplace_back(banditArcher);
				break;
			}
			case 2: {
				std::vector<unsigned> loot;
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(2);
				loot.emplace_back(2);
				loot.emplace_back(3);
				loot.emplace_back(4);
				loot.emplace_back(5);
				loot.emplace_back(6);
				loot.emplace_back(12);
				auto banditSwordsman = std::make_shared<Enemy>("Banditen Schwertkämpfer", 20, 3, 7, loot);
				generatedEnemies->emplace_back(banditSwordsman);
				break;
			}
			default: {
				std::vector<unsigned> loot;
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(0);
				loot.emplace_back(2);
				loot.emplace_back(3);
				loot.emplace_back(4);
				loot.emplace_back(5);
				loot.emplace_back(6);
				loot.emplace_back(12);
				loot.emplace_back(12);
				auto bandit = std::make_shared<Enemy>("Bandit", 20, 3, 5, loot);
				generatedEnemies->emplace_back(bandit);
				break;
			}
		}
	}
	return *generatedEnemies;
}