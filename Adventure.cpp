//
// Created by aj on 15.05.24.
//

#include "Adventure.h"

Adventure::Adventure(){
	m_player = std::make_unique<Player>("Hans");
	//start();
	test();
};

Adventure::~Adventure() = default;

void Adventure::test() {
    std::shared_ptr<Item> testArmor = std::make_shared<Armor>(1,"BasicHelm",1,"helmet",10);
    testArmor->info();

	m_player->addItem(testArmor);
	m_player->equipArmor(testArmor);

	m_player->info();

	m_player->showInventory();

}

void Adventure::start() {

}


