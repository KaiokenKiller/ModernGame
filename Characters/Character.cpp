//
// Created by aj on 15.05.24.
//

#include "Character.h"

void Character::getDamaged(int damage, bool trueDamage){
    if (!trueDamage)
        damage -= m_defense;
    if (damage <=0)
        return;
    m_health-=damage;
    return;
}

int Character::getAttack() const {
    return m_attack;
}

int Character::getDefense() const {
    return m_defense;
}

int Character::getHealth() const {
    return m_health;
}

std::string Character::getName() const {
    return m_name;
}