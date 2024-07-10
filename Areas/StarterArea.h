//
// Created by aj on 10.07.24.
//

#ifndef MODERNGAME_STARTERAREA_H
#define MODERNGAME_STARTERAREA_H
#include "Area.h"


class StarterArea : public Area{
public:
	explicit StarterArea(const std::string &areaname = "Void", unsigned minEnemyCount = 1, unsigned maxEnemyCount = 3);
	std::vector<std::shared_ptr<Enemy>>& generateEnemies() override;
};


#endif //MODERNGAME_STARTERAREA_H
