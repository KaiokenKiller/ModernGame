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
	unsigned m_enemyTypeCount; // Should never be less than 1
	unsigned m_maxEnemyCount; // Should never be less than 1
	unsigned m_minEnemyCount; // Should never be lower than max
	Area(const std::string &areaname = "Void", unsigned minEnemyCount = 1, unsigned maxEnemyCount = 3);
public:
	virtual std::vector<std::shared_ptr<Enemy>>& generateEnemies() = 0;
	std::string getAreaname();
};


#endif //MODERNGAME_AREA_H
