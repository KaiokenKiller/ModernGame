//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ENEMY_H
#define MODERNGAME_ENEMY_H
#include "Character.h"
#include "Player.h"

class Enemy :public Character{
	std::vector<unsigned> lootPool;
public:
	Enemy(std::string name, int maxHealth, int defense, int attack);
	virtual void rewards(Player* player);
};


#endif //MODERNGAME_ENEMY_H
