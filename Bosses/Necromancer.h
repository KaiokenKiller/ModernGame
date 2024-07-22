//
// Created by aj on 22.07.24.
//

#ifndef MODERNGAME_NECROMANCER_H
#define MODERNGAME_NECROMANCER_H
#include "../Characters/Enemy.h"

class Necromancer {
public:
	static std::vector<std::shared_ptr<Enemy>>& generateEnemies();
};


#endif //MODERNGAME_NECROMANCER_H
