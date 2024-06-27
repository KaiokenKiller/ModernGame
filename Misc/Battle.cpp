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

bool Battle::enemiesAlive() {
	for (Enemy* enemy:m_enemies)
		if (enemy->isAlive())
			return true;
	return false;
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
	if (m_enemies.size()>1) {
		fmt::print("Wähle einen Gegner:\n\n");
		int i = 1;
		for (Enemy *enemy: m_enemies) {
			fmt::print("({0}) {1} ({2}/{3})\n", i, enemy->getName(), enemy->getHealth(), enemy->getMaxHealth());
			i++;
		}

		std::string s = "-1";
		//Muss sicher gemacht werden!
		while (stoi(s) > m_enemies.size() || stoi(s) < 0) {
			std::cin >> s;
		}
		if (stoi(s) == 0) {
			selectMenu();
			return;
		}
		dealDamage(m_enemies[stoi(s) - 1], m_playerAttack);
	}
	else{
		dealDamage(m_enemies[0],m_playerAttack);
	}
	if (enemiesAlive()) {
		//Reset Attack for next Turn and pass turn
		m_playerAttack = m_player->createAttack();
		enemyTurn();
	}
	else {
		endOfBattle();
	}
}

void Battle::enemyTurn() {
	int i=0;
	for (Enemy* enemy:m_enemies){
		if (enemy->isAlive()) {
			dealDamage(m_player, m_enemiesAttacks[i]);
			m_enemiesAttacks[i] = enemy->createAttack();
		}
		i++;
	}
	if (m_player->isAlive()) {
		selectMenu();
	}
	else {
		endOfBattle();
	}
}

void Battle::dealDamage(Character *character, Attack *attack) {
	if (!attack->isTrueDamage()){
		if (character->getDefense() > attack->getAttack()){
			attack->setAttack(1);
		}
		else{
			attack->setAttack(attack->getAttack()-character->getDefense());
		}
	}
	fmt::print("Der Angriff verursacht {0} Schaden!",attack->getAttack());
	character->setHealth(character->getHealth() - attack->getAttack());
}

void Battle::endOfBattle() {

}