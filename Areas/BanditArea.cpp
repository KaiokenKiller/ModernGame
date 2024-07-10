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
	std::uniform_int_distribution<> disCount(m_minEnemyCount, m_maxEnemyCount);
	std::uniform_int_distribution<> disType(0, m_enemyTypeCount - 1);
	int rngEnemyCount = disCount(gen);

	for (int i = 0; i < rngEnemyCount; ++i) {

		int rngEnemyType = disType(gen);

		switch (rngEnemyType) {
			case 0: {
				auto bandit = std::make_shared<Enemy>("Bandit", 40, 3, 5);
				generatedEnemies->push_back(bandit);
				break;
			}
			case 1: {
				auto banditArcher = std::make_shared<Enemy>("Banditen Bogenschütze", 30, 0, 10);
				generatedEnemies->push_back(banditArcher);
				break;
			}
			case 2: {
				auto banditSwordsman = std::make_shared<Enemy>("Banditen Schwertkämpfer", 50, 3, 7);
				generatedEnemies->push_back(banditSwordsman);
				break;
			}
			default: {
				auto bandit = std::make_shared<Enemy>("Bandit", 30, 0, 3);
				generatedEnemies->push_back(bandit);
				break;
			}
		}
	}
	return *generatedEnemies;
}