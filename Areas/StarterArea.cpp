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
				auto skeleton = std::make_shared<Enemy>("Skelett", 35, 5, 5);
				generatedEnemies->push_back(skeleton);
				break;
			}
			case 1: {
				auto wulf = std::make_shared<Enemy>("Wolf", 30, 0, 10);
				generatedEnemies->push_back(wulf);
				break;
			}
			case 2: {
				auto goblin = std::make_shared<Enemy>("Goblin", 40, 3, 7);
				generatedEnemies->push_back(goblin);
				break;
			}
			case 3: {
				auto slime = std::make_shared<Enemy>("Schleim", 30, 0, 3);
				generatedEnemies->push_back(slime);
				break;
			}
			default: {
				auto defaultSlime = std::make_shared<Enemy>("Schleim", 30, 0, 3);
				generatedEnemies->push_back(defaultSlime);
				break;
			}
		}
	}
	return *generatedEnemies;
}