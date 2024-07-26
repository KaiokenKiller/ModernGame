//
// Created by aj on 10.07.24.
//

#ifndef MODERNGAME_ITEMLIST_H
#define MODERNGAME_ITEMLIST_H
#include "../Items/Armor.h"
#include "../Items/Weapon.h"
#include "../Items/Consumeable.h"

class Itemlist {
protected:
	std::vector<std::shared_ptr<Item>> m_itemlist;
public:
	Itemlist();
	std::shared_ptr<Item> getItem(unsigned id);
	void addItem(unsigned id);
	void removeItem(unsigned int id);

	void showInventory();


};


#endif //MODERNGAME_ITEMLIST_H
