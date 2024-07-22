//
// Created by aj on 22.07.24.
//

#ifndef MODERNGAME_CAVEAREA_H
#define MODERNGAME_CAVEAREA_H
#include "Area.h"

class CaveArea : public Area{
public:
	CaveArea(const std::string &areaname = "Höhle", unsigned minEnemyCount = 2, unsigned maxEnemyCount = 4);
	std::vector<std::shared_ptr<Enemy>> & generateEnemies() override;
};


#endif //MODERNGAME_CAVEAREA_H
