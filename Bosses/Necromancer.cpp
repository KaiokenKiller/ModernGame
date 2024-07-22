//
// Created by aj on 22.07.24.
//

#include "Necromancer.h"

std::vector<std::shared_ptr<Enemy>> &Necromancer::generateEnemies() {
	auto generatedEnemies = new std::vector<std::shared_ptr<Enemy>>;

	std::vector<unsigned> loot1;
	loot1.push_back(15);
	loot1.push_back(16);
	loot1.push_back(17);

	auto necromancer = std::make_shared<Enemy>("Nekromant", 45, 5, 13,loot1);
	generatedEnemies->emplace_back(necromancer);

	std::vector<unsigned> loot2;
	loot2.push_back(0);
	loot2.push_back(0);
	loot2.push_back(2);
	loot2.push_back(3);
	loot2.push_back(4);
	loot2.push_back(5);
	loot2.push_back(6);
	loot2.push_back(13);
	loot2.push_back(18);

	auto skeletonWarrior = std::make_shared<Enemy>("Skelett Krieger", 35, 5, 7,loot2);
	auto skeletonWarrior2 = std::make_shared<Enemy>("Skelett Krieger", 35, 5, 7,loot2);
	generatedEnemies->emplace_back(skeletonWarrior);
	generatedEnemies->emplace_back(skeletonWarrior2);


	return *generatedEnemies;
}
