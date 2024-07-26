//
// Created by aj on 26.07.24.
//

#ifndef MODERNGAME_CONSUMEABLE_H
#define MODERNGAME_CONSUMEABLE_H
#include "Item.h"
#include "../Misc/Attack.h"

class Consumeable : public Item{
protected:
	int m_modifyValue;
	double m_modifyMultiplier;
public:
	// valid tags are healing,throwable,buffDamage
	Consumeable(unsigned int id, const std::string &itemName, unsigned int quantity, Tag tag, int modifyValue, double modifyMultiplier);
	int healing(int health) const;
	std::shared_ptr<Attack> throwable() const;
	std::shared_ptr<Attack> buffDamage(std::shared_ptr<Attack> attack) const;
	void info() override;
};


#endif //MODERNGAME_CONSUMEABLE_H
