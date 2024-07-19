//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_CHARACTER_H
#define MODERNGAME_CHARACTER_H
#include "iostream"
#include "vector"
#include "memory"
#include "../Misc/Attack.h"
#include <fmt/core.h>

class Character{
protected:
    std::string m_name;
    int m_health;
	int m_maxHealth;
    int m_attack;
	int m_defense;



public:

	virtual std::shared_ptr<Attack> createAttack();





	[[nodiscard]] bool isAlive() const;

    [[nodiscard]] int getHealth() const;

	[[nodiscard]] int getMaxHealth() const;

    [[nodiscard]] std::string getName() const;

	[[nodiscard]] int getAttack() const;

	[[nodiscard]] int getDefense() const;

    void setName(std::string &name);

    void setHealth(int health);

	void setMaxHealth(int maxHealth);

	void setAttack(int attack);

	void setDefense(int defense);


	virtual void info();

};


#endif //MODERNGAME_CHARACTER_H
