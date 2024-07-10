//
// Created by aj on 15.05.24.
//

#include "Attack.h"

Attack::Attack(int attackValue, bool trueDamage) {
	m_attackValue = attackValue;
	m_trueDamage = trueDamage;
}

int Attack::getAttack() const {
	return m_attackValue;
}

bool Attack::isTrueDamage() const {
	return m_trueDamage;
}

void Attack::setAttack(int attack) {
	m_attackValue = attack;
}

void Attack::setTrueDamage(bool trueDamage) {
	m_trueDamage = trueDamage;
}