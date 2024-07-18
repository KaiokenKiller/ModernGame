//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ENEMY_H
#define MODERNGAME_ENEMY_H
#include "Character.h"
#include "Player.h"
#include <random>

class Enemy :public Character{
	std::vector<unsigned> m_lootPool;
public:
	Enemy(const std::string &name, int maxHealth, int defense, int attack,const std::vector<unsigned>& lootPool);
	virtual void rewards(const std::shared_ptr<Player> &player);
};


#endif //MODERNGAME_ENEMY_H
