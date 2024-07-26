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
	fmt::print("Spieler:\n\n{0} ({1}/{2})\n\nGegner:\n\n",m_player->getName(), m_player->getHealth(), m_player->getMaxHealth());
	for (const auto& enemy:m_enemies) {
		if (enemy->isAlive())
			fmt::print("{0} ({1}/{2})\n",enemy->getName(),enemy->getHealth(),enemy->getMaxHealth());
	}

	std::string choice = "-1";
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4"){
		fmt::print("\n(1): Angriff\n(2): Inventar\n(3): Status\n(4): Gegner inspizieren\n");
		std::cin >> choice;
	}
	if (choice == "1")
		selectAttack();
	if (choice == "2")
		selectInventory();
	if (choice == "3")
		selectStatus();
	if (choice == "4")
		selectInspectEnemy();
}

void Battle::selectAttack() {
	int i = enemySelection();
	switch (i) {
		case RETURN: {
			selectMenu();
			return;
		}
		case ENEMIES_EMPTY: {
			return;
		}
		default: {
			dealDamage(m_enemies[i], m_playerAttack);
			if (!m_enemies[i]->isAlive())
				fmt::print("{0} wurde besiegt!", m_enemies[i]->getName());
			std::cin.get();
			std::cin.get();
			if (enemiesAlive()) {
				//Reset Attack for next Turn and pass turn
				m_playerAttack = m_player->createAttack();
				enemyTurn();
			} else {
				endOfBattle();
			}
		}
	}
}

void Battle::selectInventory() {
	std::string choice;
	bool finished = false;

	while (!finished) {
		m_player->showInventory();
		fmt::print("(0): Zurück\n(ID): Wähle einen Gegenstand:\n");
		std::cin >> choice;

		if (choice == "0") {
			finished = true;
		} else {
			std::shared_ptr<Item> temp = m_player->getItem(std::stoi(choice));
			if (temp == nullptr) {
				fmt::print("Du besitz keinen solchen Gegenstand!\n");
				std::cin.get();
			} else {
				temp->info();
				choice = "";
				while (choice != "0" && choice != "1") {
					fmt::print("Möchtest du diesen Gegenstand benutzen?\n(0): Nein\n(1): Ja\n");
					std::cin >> choice;
				}
				if (choice == "1") {
					if (temp->getTag() == Tag::helmet || temp->getTag() == Tag::torso || temp->getTag() == Tag::legs ||
						temp->getTag() == Tag::gloves) {
						m_player->equipArmor(temp);
					}
					if (temp->getTag() == Tag::weapon) {
						m_player->equipWeapon(temp);
						m_playerAttack = m_player->createAttack();
					}
					if (temp->getTag() == Tag::healing) {
						m_player->setHealth(
								std::dynamic_pointer_cast<Consumeable>(temp)->healing(m_player->getHealth()));
						m_player->removeItem(temp->getId());
					}
					if (temp->getTag() == Tag::throwable) {
						int i = enemySelection();
						switch (i) {
							case RETURN: {
								break;
							}
							case ENEMIES_EMPTY: {
								return;
							}
							default: {
								dealDamage(m_enemies[i],std::dynamic_pointer_cast<Consumeable>(temp)->throwable());
								m_player->removeItem(temp->getId());
								break;
							}
						}
					}
					if (temp->getTag() == Tag::buffDamage){
						m_playerAttack = std::dynamic_pointer_cast<Consumeable>(temp)->buffDamage(m_playerAttack);
						m_player->removeItem(temp->getId());
					}
				}
			}
		}
	}
	selectMenu();
}
void Battle::selectStatus(){
	m_player->info();
	std::cin.get();
	std::cin.get();
	selectMenu();
}

void Battle::selectInspectEnemy(){
	int i = enemySelection();
	switch (i) {
		case RETURN: {
			selectMenu();
			return;
		}
		case ENEMIES_EMPTY: {
			return;
		}
		default: {
			m_enemies[i]->info();
			std::cin.get();
			std::cin.get();
			selectMenu();
		}
	}
}

int Battle::enemySelection() {
	if (!m_enemies.empty()) {
		fmt::print("(0): Zurück\n(Nr) Wähle einen Gegner:\n\n");
		int i = 1;
		for (const auto &enemy: m_enemies) {
			if (enemy->isAlive()) {
				fmt::print("({0}) {1} ({2}/{3})\n", i, enemy->getName(), enemy->getHealth(), enemy->getMaxHealth());
				i++;
			}
		}

		std::string choice = "-1";

		while (stoi(choice) > m_enemies.size() - m_deadEnemies || stoi(choice) < 0) {
			std::cin >> choice;
		}
		if (stoi(choice) == 0) {
			return RETURN;
		}

		i = -1;
		int j = stoi(choice);
		while (j) {
			i++;
			if (m_enemies[i]->isAlive()) {
				j--;
			}
		}
		return i;
	}
	return ENEMIES_EMPTY;
}

void Battle::enemyTurn() {
	int i=0;
	for (const auto& enemy:m_enemies){
		if (enemy->isAlive()) {
			fmt::print("{0} greift an!\n",enemy->getName());
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

void Battle::dealDamage(const std::shared_ptr<Character>& character, const std::shared_ptr<Attack>& attack) {
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
		std::cin.get();
	}
}