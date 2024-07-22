//
// Created by aj on 22.07.24.
//

#include "CaveTroll.h"



std::shared_ptr<Enemy> CaveTroll::generateEnemies() {
	std::vector<unsigned> loot;
	loot.emplace_back(14);

	auto caveTroll = std::make_shared<Enemy>("Höhlentroll",60,5,15,loot);
	return caveTroll;
}
