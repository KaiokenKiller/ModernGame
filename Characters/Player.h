//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_PLAYER_H
#define MODERNGAME_PLAYER_H
#include "Character.h"
#include "../Misc/equippedArmor.h"
#include "../Items/Weapon.h"
#include "../Misc/Itemlist.h"

class Player : public Character{
protected:
	std::unique_ptr<Itemlist> m_inventory;
    std::unique_ptr<equippedArmor> m_armorSet;
	std::shared_ptr<Weapon> m_equippedWeapon;
	int m_baseDefense;

public:
    explicit Player(const std::string &name,int maxHealth = 100, int defense = 0, int attack = 10);
    ~Player();


	std::shared_ptr<Item> getItem(unsigned id);
	void addItem(const std::shared_ptr<Item>& item);
	void showInventory();

    void equipArmor(const std::shared_ptr<Item>& armor);
    void unequipArmor(const std::shared_ptr<Item>& armor);

	void updateDefense();

	void equipWeapon(int id);
	void unequipWeapon(int id);

	[[nodiscard]] int getBaseDefense() const;




	void info() override;
};


#endif //MODERNGAME_PLAYER_H
