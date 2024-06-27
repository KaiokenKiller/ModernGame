//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_PLAYER_H
#define MODERNGAME_PLAYER_H
#include "Character.h"
#include "../Misc/equippedArmor.h"

class Player : public Character{
protected:
    std::unique_ptr<equippedArmor> m_armorSet;
	std::vector<std::shared_ptr<Item>> m_inventory;
	int m_baseDefense;

public:
    Player();
    Player(std::string name,int maxHealth = 100, int defense = 0, int attack = 10);
    ~Player();


	std::shared_ptr<Item> getItem(unsigned id);

	void addItem(const std::shared_ptr<Item>& item);

	void showInventory();

    void equipArmor(const std::shared_ptr<Item>& armor);

    void unequipArmor(const std::shared_ptr<Item>& armor);

	void updateDefense();

	int getBaseDefense() const;




	void info() override;
};


#endif //MODERNGAME_PLAYER_H
