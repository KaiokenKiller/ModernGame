//
// Created by aj on 10.07.24.
//

#include "BanditArea.h"

BanditArea::BanditArea(const std::string &areaname, unsigned minEnemyCount, unsigned maxEnemyCount): Area(areaname,minEnemyCount,maxEnemyCount){
	m_enemyTypeCount = 4;
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
				std::vector<unsigned> loot{0,0,0,0,2,3,4,5,6,12,12};

				auto bandit = std::make_shared<Enemy>("Bandit", 20, 3, 5, loot);
				generatedEnemies->emplace_back(bandit);
				break;
			}
			case 1: {
				std::vector<unsigned> loot{0,0,0,3,4,5,6,12,13};

				auto banditArcher = std::make_shared<Enemy>("Banditen Bogenschütze", 20, 0, 10, loot);
				generatedEnemies->emplace_back(banditArcher);
				break;
			}
			case 2: {
				std::vector<unsigned> loot{0,0,2,2,3,4,5,6,12};

				auto banditSwordsman = std::make_shared<Enemy>("Banditen Schwertkämpfer", 20, 3, 7, loot);
				generatedEnemies->emplace_back(banditSwordsman);
				break;
			}
			default: {
				std::vector<unsigned> loot{0,0,0,0,2,3,4,5,6,12,12};

				auto bandit = std::make_shared<Enemy>("Bandit", 20, 3, 5, loot);
				generatedEnemies->emplace_back(bandit);
				break;
			}
		}
	}
	return *generatedEnemies;
}