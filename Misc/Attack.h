//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ATTACK_H
#define MODERNGAME_ATTACK_H

class Attack {
private:
	int m_attackValue;
	bool m_trueDamage;
public:
	Attack(int attackValue, bool trueDamage = false);

	int getAttack();
	bool isTrueDamage();
	void setAttack(int attack);
	void setTrueDamage(bool trueDamage);
};


#endif //MODERNGAME_ATTACK_H
