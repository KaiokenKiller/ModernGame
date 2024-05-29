//
// Created by aj on 15.05.24.
//

#include "Character.h"

void Character::getDamaged(Attack attack){

    return;
}


int Character::getHealth() const {
    return m_health;
}

std::string Character::getName() const {
    return m_name;
}

void Character::setHealth(int health) {
    m_health = health;
}

void Character::setName(std::string &name) {
    m_name = name;
}