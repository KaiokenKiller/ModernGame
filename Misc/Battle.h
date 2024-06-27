//
// Created by aj on 27.06.24.
//

#ifndef MODERNGAME_BATTLE_H
#define MODERNGAME_BATTLE_H
#include "../Characters/Player.h"
#include "../Characters/Enemy.h"


class Battle {
private:
	Player* m_player;
	Attack* m_playerAttack;
	std::vector<Enemy*> m_enemies;
	std::vector<Attack*> m_enemiesAttacks;
public:
	Battle(Player* player, Enemy* enemy);
	Battle(Player* player,std::vector<Enemy*> enemies);

	bool enemiesAlive();
	void selectMenu();
	void selectAttack();
	void enemyTurn();
	void dealDamage(Character* character, Attack* attack);
	void endOfBattle();
};


#endif //MODERNGAME_BATTLE_H
