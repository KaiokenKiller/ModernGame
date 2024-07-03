//
// Created by aj on 15.05.24.
//

#include "Adventure.h"

Adventure::Adventure(){
	m_player = std::make_shared<Player>("Hans");
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

	std::shared_ptr<Enemy> dummy1 = std::make_shared<Enemy>("Napstablock",35,2,2);
	std::shared_ptr<Enemy> dummy2 = std::make_shared<Enemy>("Mad dummy",55,0,20);

	std::vector<std::shared_ptr<Enemy>>* temp = new std::vector<std::shared_ptr<Enemy>>;
	temp->emplace_back(dummy1);
	temp->emplace_back(dummy2);

	Battle(m_player,temp);

}

void Adventure::start() {

}


