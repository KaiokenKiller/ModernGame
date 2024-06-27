//
// Created by aj on 15.05.24.
//

#include "Attack.h"

int Attack::getAttack() {
	return m_attackValue;
}

bool Attack::isTrueDamage() {
	return m_trueDamage;
}

void Attack::setAttack(int attack) {
	m_attackValue = attack;
}

void Attack::setTrueDamage(bool trueDamage) {
	m_trueDamage = trueDamage;
}