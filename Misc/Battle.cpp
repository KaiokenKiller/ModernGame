//
// Created by aj on 27.06.24.
//

#include "Battle.h"

Battle::Battle(std::shared_ptr<Player> &player, std::shared_ptr<Enemy>& enemy) {
	m_player = player;
	m_enemies.push_back(enemy);
	m_playerAttack = m_player->createAttack();
	m_enemiesAttacks.push_back(enemy->createAttack());
	m_deadEnemies = 0;
	selectMenu();
}

Battle::Battle(std::shared_ptr<Player> &player, std::vector<std::shared_ptr<Enemy>> &enemies) {
	m_player = player;
	for (const auto& enemy: enemies){
		m_enemies.push_back(enemy);
	}
	m_playerAttack = m_player->createAttack();
	
	int i=0;
	for (const auto& enemy: m_enemies){
		m_enemiesAttacks.push_back(enemy->createAttack());
		i++;
	}
	m_deadEnemies = 0;
	selectMenu();
}

bool Battle::enemiesAlive() {
	bool alive = false;
	m_deadEnemies = 0;
	for (const auto& enemy:m_enemies) {
		if (enemy->isAlive())
			alive = true;
		else
			m_deadEnemies++;

	}
	return alive;
}

void Battle::selectMenu() {
	fmt::print("\nSpieler:\n\n{0} ({1}/{2})\n\nEnemies:\n\n",m_player->getName(), m_player->getHealth(), m_player->getMaxHealth());
	for (const auto& enemy:m_enemies) {
		if (enemy->isAlive())
			fmt::print("{0} ({1}/{2})\n",enemy->getName(),enemy->getHealth(),enemy->getMaxHealth());
	}

	std::string s = "-1";
	while (s != "1"){
		fmt::print("(1): Angriff\n");
		std::cin >> s;
	}
	if (s == "1")
		selectAttack();
}

void Battle::selectAttack() {
	if (!m_enemies.empty()) {
		fmt::print("Wähle einen Gegner:\n\n");
		int i = 1;
		for (const auto& enemy: m_enemies) {
			if (enemy->isAlive()){
				fmt::print("({0}) {1} ({2}/{3})\n", i, enemy->getName(), enemy->getHealth(), enemy->getMaxHealth());
				i++;
				}
		}

		std::string s = "-1";
		//Muss sicher gemacht werden!
		while (stoi(s) > m_enemies.size()-m_deadEnemies || stoi(s) < 0) {
			std::cin >> s;
		}
		if (stoi(s) == 0) {
			selectMenu();
			return;
		}

		i = -1;
		int j = stoi(s);
		while(j){
			i++;
			if (m_enemies[i]->isAlive()){
				j--;
			}
		}

		dealDamage(m_enemies[i], m_playerAttack);
		if (!m_enemies[i]->isAlive())
			fmt::print("{0} wurde besiegt!",m_enemies[i]->getName());
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
	for (const auto& enemy:m_enemies){
		if (enemy->isAlive()) {
			fmt::print("\n{0} greift an!\n",enemy->getName());
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

void Battle::dealDamage(const std::shared_ptr<Character>& character, Attack *attack) {
	if (!attack->isTrueDamage()){
		if (character->getDefense() >= attack->getAttack()){
			attack->setAttack(1);
		}
		else{
			attack->setAttack(attack->getAttack()-character->getDefense());
		}
	}
	fmt::print("Der Angriff verursacht {0} Schaden!\n",attack->getAttack());
	character->setHealth(character->getHealth() - attack->getAttack());
}

void Battle::endOfBattle() {
	if (!m_player->isAlive()){
		fmt::print("{0} erliegt seinen Wunden!\n",m_player->getName());
	}
	else {
		fmt::print("{0} konnte den Kampf für sich entscheiden!\n",m_player->getName());
		m_player->setHealth(m_player->getMaxHealth());
		for (const auto& enemy: m_enemies){
			enemy->rewards(m_player);
		}
	}
}