//
// Created by aj on 22.07.24.
//

#include "Necromancer.h"

std::vector<std::shared_ptr<Enemy>> &Necromancer::generateEnemies() {
	auto generatedEnemies = new std::vector<std::shared_ptr<Enemy>>;

	std::vector<unsigned> loot1{15,16,17};

	auto necromancer = std::make_shared<Enemy>("Nekromant", 45, 5, 13,loot1);
	generatedEnemies->emplace_back(necromancer);

	std::vector<unsigned> loot2{0,0,2,3,4,5,6,13,18};

	auto skeletonWarrior = std::make_shared<Enemy>("Skelett Krieger", 35, 5, 7,loot2);
	auto skeletonWarrior2 = std::make_shared<Enemy>("Skelett Krieger", 35, 5, 7,loot2);
	generatedEnemies->emplace_back(skeletonWarrior);
	generatedEnemies->emplace_back(skeletonWarrior2);


	return *generatedEnemies;
}
