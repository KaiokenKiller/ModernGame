//
// Created by aj on 10.07.24.
//

#include "Itemlist.h"

Itemlist::Itemlist() {

	// Creating all items
	m_itemlist.emplace_back(nullptr);
	m_itemlist.emplace_back(std::make_shared<Weapon>(1,"Holzschwert",0,Tag::weapon,3,false));
	m_itemlist.emplace_back(std::make_shared<Weapon>(2,"Eisenschwert",0,Tag::weapon,5,false));
	m_itemlist.emplace_back(std::make_shared<Armor>(3,"Lederkappe",0,Tag::helmet,1));
	m_itemlist.emplace_back(std::make_shared<Armor>(4,"Lederbrustpanzer",0,Tag::torso,2));
	m_itemlist.emplace_back(std::make_shared<Armor>(5,"Lederhose",0,Tag::legs,1));
	m_itemlist.emplace_back(std::make_shared<Armor>(6,"Lederhandschuhe",0,Tag::gloves,1));
	m_itemlist.emplace_back(std::make_shared<Armor>(7,"Farmerhut",0,Tag::helmet,1));
	m_itemlist.emplace_back(std::make_shared<Armor>(8,"Farmerhemd",0,Tag::torso,1));
	m_itemlist.emplace_back(std::make_shared<Armor>(9,"Farmerhose",0,Tag::legs,1));
	m_itemlist.emplace_back(std::make_shared<Armor>(10,"Farmerhandschuhe",0,Tag::gloves,1));
	m_itemlist.emplace_back(std::make_shared<Weapon>(11,"Eisenhacke",0,Tag::weapon,4,false));
	m_itemlist.emplace_back(std::make_shared<Weapon>(12,"Dolch",0,Tag::weapon,4,false));
	m_itemlist.emplace_back(std::make_shared<Weapon>(13,"Bogen",0,Tag::weapon,6,false));
	m_itemlist.emplace_back(std::make_shared<Weapon>(14,"Keule des Trolls",0,Tag::weapon,10,false));
	m_itemlist.emplace_back(std::make_shared<Weapon>(15,"Stab des Nekromanten",0,Tag::weapon,9,false));
	m_itemlist.emplace_back(std::make_shared<Armor>(16,"Robe des Nekromanten",0,Tag::torso,4));
	m_itemlist.emplace_back(std::make_shared<Armor>(17,"Ring des Nekromanten",0,Tag::gloves,3));
	m_itemlist.emplace_back(std::make_shared<Armor>(18,"Kettenhemd",0,Tag::torso,3));
	m_itemlist.emplace_back(std::make_shared<Consumeable>(19,"Heiltrank",0,Tag::healing,20,1));
	m_itemlist.emplace_back(std::make_shared<Consumeable>(20,"Stärketrank",0,Tag::buffDamage,0,1.5));
	m_itemlist.emplace_back(std::make_shared<Consumeable>(21,"Bombe",0,Tag::throwable,10,1));

}

std::shared_ptr<Item> Itemlist::getItem(unsigned int id) {
	if (id < m_itemlist.size() && m_itemlist[id] != nullptr && m_itemlist[id]->getQuantity() > 0)
			return m_itemlist[id];
	return nullptr;
}

void Itemlist::addItem(const unsigned id) {
	if (id < m_itemlist.size() && m_itemlist[id] != nullptr){
		m_itemlist[id]->setQuantity(m_itemlist[id]->getQuantity() + 1);
		fmt::print("Du hast ein \"{0}\" erhalten!\n", m_itemlist[id]->getItemName());
	}
}

void Itemlist::removeItem(const unsigned id) {
	if (id < m_itemlist.size() && id != 0)
		if (m_itemlist[id]->getQuantity() > 0)
			m_itemlist[id]->setQuantity(m_itemlist[id]->getQuantity()-1);
}

void Itemlist::showInventory() {
	for (const auto& element:m_itemlist){
		if (element != nullptr) {
			if (element->getQuantity() > 0)
				fmt::print("{0:03}. {1} [{2}] {3}x\n", element->getId(), element->getItemName(), element->getTagString(),
						   element->getQuantity());
		}
	}
	fmt::print("\n");
}
