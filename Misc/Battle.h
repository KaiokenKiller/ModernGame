//
// Created by aj on 27.06.24.
//

#ifndef MODERNGAME_BATTLE_H
#define MODERNGAME_BATTLE_H
#include "../Characters/Player.h"
#include "../Characters/Enemy.h"


class Battle {
private:
	std::shared_ptr<Player> m_player;
	Attack* m_playerAttack;
	std::vector<std::shared_ptr<Enemy>> m_enemies;
	unsigned m_deadEnemies;
	std::vector<Attack*> m_enemiesAttacks;
public:
	Battle(std::shared_ptr<Player> &player,std::vector<std::shared_ptr<Enemy>> &enemies);
	Battle(std::shared_ptr<Player> &player, std::shared_ptr<Enemy> &enemy);


	bool enemiesAlive();
	void selectMenu();
	void selectAttack();
	void enemyTurn();
	static void dealDamage(const std::shared_ptr<Character>& character, Attack* attack);
	void endOfBattle();
};


#endif //MODERNGAME_BATTLE_H
