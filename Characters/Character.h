//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_CHARACTER_H
#define MODERNGAME_CHARACTER_H
#include "iostream"
#include "../Tweaks/Attack.h"


class Character{
protected:
    std::string m_name;
    int m_health;
    int m_defense;
    int m_attack;

public:

    virtual void getDamaged(Attack attack, bool trueDamage);













    int getHealth() const;

    std::string getName() const;

    int getDefense() const;

    int getAttack() const;
};


#endif //MODERNGAME_CHARACTER_H
