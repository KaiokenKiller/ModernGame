//
// Created by aj on 10.07.24.
//

#ifndef MODERNGAME_WEAPON_H
#define MODERNGAME_WEAPON_H
#include "Item.h"
#include "../Misc/Attack.h"

class Weapon : public Item{
protected:
	int m_attackValue;
	bool m_trueDamage;
public:
	Weapon(unsigned id = 0,const std::string &itemName = "empty", unsigned quantity = 0, const std::string &tag = "", int attackValue = 0, bool trueDamage = false);
	void modifyAttack(Attack &attack);

	int getAttackValue() const;
	bool isTrueDamage() const;

	void setAttackValue(int attack);
	void setTrueDamage(bool trueDamage);

	void info() override;
};


#endif //MODERNGAME_WEAPON_H
