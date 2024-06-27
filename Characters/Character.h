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

	virtual Attack* createAttack();





	bool isAlive();

    int getHealth() const;

	int getMaxHealth() const;

    std::string getName() const;

	int getAttack() const;

	int getDefense() const;

    void setName(std::string &name);

    void setHealth(int health);

	void setMaxHealth(int maxHealth);

	void setAttack(int attack);

	void setDefense(int defense);


	virtual void info();

};


#endif //MODERNGAME_CHARACTER_H
