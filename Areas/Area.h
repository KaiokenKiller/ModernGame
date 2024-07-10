//
// Created by aj on 03.07.24.
//

#ifndef MODERNGAME_AREA_H
#define MODERNGAME_AREA_H

#include "../Characters/Enemy.h"
#include <random>
#include <utility>


class Area {
protected:
	std::string m_areaname;
	unsigned enemyTypeCount = 1; // Should never be less than 1
public:
	virtual std::vector<std::shared_ptr<Enemy>>& generateEnemies() = 0;
	std::string getAreaname();
};


#endif //MODERNGAME_AREA_H
