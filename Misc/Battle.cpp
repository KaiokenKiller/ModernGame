//
// Created by aj on 27.06.24.
//

#include "Battle.h"

Battle::Battle(Player *player, Enemy *enemy) {
	m_player = player;
	m_enemies.push_back(enemy);
	selectMenu();
}

Battle::Battle(Player *player, std::vector<Enemy *> enemies) {
	m_player = player;
	m_playerAttack = m_player->createAttack();
	m_enemies = std::move(enemies);
	
	int i=0;
	for (Enemy* enemy: m_enemies){
		m_enemiesAttacks[i] = enemy->createAttack();
		i++;
	}
	selectMenu();
}

void Battle::selectMenu() {
	fmt::print("Spieler:\n\n{0} ({1}/{2})\n\nEnemies:\n\n",m_player->getName(), m_player->getHealth(), m_player->getMaxHealth());
	for (Enemy* enemy:m_enemies) {
		fmt::print("{0} ({1}/{2})\n",enemy->getName(),enemy->getHealth(),enemy->getMaxHealth());
	}

	std::string s = "-1";
	while (s != "1"){
		fmt::print("(1): Angriff");
		std::cin >> s;
	}
	if (s == "1")
		selectAttack();
}

void Battle::selectAttack() {
	if (m_enemies.size()>1){
		fmt::print("Wähle einen Gegner:\n\n");
		int i = 1;
		for (Enemy* enemy:m_enemies) {
			fmt::print("({0}) {1} ({2}/{3})\n",i,enemy->getName(),enemy->getHealth(),enemy->getMaxHealth());
			i++;
		}

		std::string s = "-1";
		//Muss sicher gmeacht werden!
		while (stoi(s) > m_enemies.size() || stoi(s) <0){
			std::cin >> s;
		}
		if (stoi(s) == 0){
			selectMenu();
			return;
		}
		m_enemies[stoi(s)]->getDamaged(m_playerAttack);
		enemyTurn();
	}
}

void Battle::enemyTurn() {

}