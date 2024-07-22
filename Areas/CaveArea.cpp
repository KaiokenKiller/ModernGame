//
// Created by aj on 22.07.24.
//

#include "CaveArea.h"

CaveArea::CaveArea(const std::string &areaname, unsigned minEnemyCount, unsigned maxEnemyCount){
	m_areaname = areaname;
	m_enemyTypeCount = 4;
	m_minEnemyCount = minEnemyCount;
	m_maxEnemyCount = maxEnemyCount;
}

std::vector<std::shared_ptr<Enemy>> &CaveArea::generateEnemies() {
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
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(1);
				loot.push_back(1);
				loot.push_back(2);
				loot.push_back(3);
				loot.push_back(6);
				auto skeleton = std::make_shared<Enemy>("Skelett", 20, 5, 5,loot);
				generatedEnemies->emplace_back(skeleton);
				break;
			}
			case 1: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(3);
				loot.push_back(4);
				loot.push_back(5);
				loot.push_back(6);

				auto goblin = std::make_shared<Enemy>("Goblin", 25, 3, 7,loot);
				generatedEnemies->emplace_back(goblin);
				break;
			}
			case 2: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(2);
				loot.push_back(4);
				loot.push_back(12);
				loot.push_back(18);

				auto giantSpider = std::make_shared<Enemy>("Riesen Spinne", 30, 2, 10,loot);
				generatedEnemies->emplace_back(giantSpider);
				break;
			}
			case 3: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(2);
				loot.push_back(3);
				loot.push_back(4);
				loot.push_back(5);
				loot.push_back(6);
				loot.push_back(13);
				loot.push_back(18);

				auto skeletonWarrior = std::make_shared<Enemy>("Skelett Krieger", 35, 5, 7,loot);
				generatedEnemies->emplace_back(skeletonWarrior);
				break;
			}
			default: {
				std::vector<unsigned> loot;
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(0);
				loot.push_back(3);
				loot.push_back(4);
				loot.push_back(5);
				loot.push_back(6);

				auto goblin = std::make_shared<Enemy>("Goblin", 25, 3, 7,loot);
				generatedEnemies->emplace_back(goblin);
				break;
			}
		}
	}
	return *generatedEnemies;
}
