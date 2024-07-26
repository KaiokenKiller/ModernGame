//
// Created by aj on 27.06.24.
//

#ifndef MODERNGAME_BATTLE_H
#define MODERNGAME_BATTLE_H
#include "../Characters/Player.h"
#include "../Characters/Enemy.h"


class Battle {
protected:
	static constexpr int RETURN = -1;
	static constexpr int ENEMIES_EMPTY = -2;
public:
	std::shared_ptr<Player> m_player;
	std::shared_ptr<Attack> m_playerAttack;
	std::vector<std::shared_ptr<Enemy>> m_enemies;
	unsigned m_deadEnemies;
	std::vector<std::shared_ptr<Attack>> m_enemiesAttacks;

	Battle(std::shared_ptr<Player> &player,std::vector<std::shared_ptr<Enemy>> &enemies);
	Battle(std::shared_ptr<Player> &player, std::shared_ptr<Enemy> &enemy);


	bool enemiesAlive();
	void selectMenu();
	void selectAttack();
	void selectInventory();
	void selectStatus();
	void selectInspectEnemy();
	int enemySelection();
	void enemyTurn();
	static void dealDamage(const std::shared_ptr<Character>& character, const std::shared_ptr<Attack>& attack);
	void endOfBattle();





};


#endif //MODERNGAME_BATTLE_H
