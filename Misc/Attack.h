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
	explicit Attack(int attackValue, bool trueDamage = false);

	int getAttack() const;
	bool isTrueDamage() const;
	void setAttack(int attack);
	void setTrueDamage(bool trueDamage);
};


#endif //MODERNGAME_ATTACK_H
