//
// Created by aj on 10.07.24.
//

#ifndef MODERNGAME_BANDITAREA_H
#define MODERNGAME_BANDITAREA_H
#include "Area.h"

class BanditArea :public Area{
public:
	explicit BanditArea(const std::string &areaname = "Void", unsigned minEnemyCount = 1, unsigned maxEnemyCount = 3);
	std::vector<std::shared_ptr<Enemy>>& generateEnemies() override;
};


#endif //MODERNGAME_BANDITAREA_H
