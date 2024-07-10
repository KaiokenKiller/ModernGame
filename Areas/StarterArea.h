//
// Created by aj on 10.07.24.
//

#ifndef MODERNGAME_STARTERAREA_H
#define MODERNGAME_STARTERAREA_H
#include "Area.h"


class StarterArea : public Area{
public:
	explicit StarterArea(const std::string &areaname = "Void");
	std::vector<std::shared_ptr<Enemy>>& generateEnemies() override;
};


#endif //MODERNGAME_STARTERAREA_H
