//
// Created by aj on 10.07.24.
//

#include "StarterArea.h"

StarterArea::StarterArea(const std::string &areaname, unsigned minEnemyCount, unsigned maxEnemyCount){
	m_areaname = areaname;
	m_enemyTypeCount = 4;
	m_minEnemyCount = minEnemyCount;
	m_maxEnemyCount = maxEnemyCount;
}

//randomly generate Vector of enemies from the Area and return it
std::vector<std::shared_ptr<Enemy>>& StarterArea::generateEnemies() {
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
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(1);
				loot.push_back(1);
				loot.push_back(2);
				loot.push_back(3);
				loot.push_back(6);
				auto skeleton = std::make_shared<Enemy>("Skelett", 20, 5, 5,loot);
				generatedEnemies->push_back(skeleton);
				break;
			}
			case 1: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(1);
				loot.push_back(5);
				loot.push_back(5);

				auto wulf = std::make_shared<Enemy>("Wolf", 20, 0, 10,loot);
				generatedEnemies->push_back(wulf);
				break;
			}
			case 2: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(3);
				loot.push_back(4);
				loot.push_back(5);
				loot.push_back(6);

				auto goblin = std::make_shared<Enemy>("Goblin", 25, 3, 7,loot);
				generatedEnemies->push_back(goblin);
				break;
			}
			case 3: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				auto slime = std::make_shared<Enemy>("Schleim", 15, 0, 3,loot);
				generatedEnemies->push_back(slime);
				break;
			}
			default: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				auto defaultSlime = std::make_shared<Enemy>("Schleim", 15, 0, 3,loot);
				generatedEnemies->push_back(defaultSlime);
				break;
			}
		}
	}
	return *generatedEnemies;
}