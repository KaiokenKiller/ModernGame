//
// Created by aj on 03.07.24.
//

#include "Area.h"

std::string Area::getAreaname() {
	return m_areaname;
}

Area::Area(const std::string &areaname, unsigned int minEnemyCount, unsigned int maxEnemyCount) {
	m_areaname = areaname;
	m_minEnemyCount = minEnemyCount;
	m_maxEnemyCount = maxEnemyCount;
}


