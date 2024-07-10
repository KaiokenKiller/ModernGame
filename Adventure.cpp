//
// Created by aj on 15.05.24.
//

#include "Adventure.h"

Adventure::Adventure(){
	std::string name;
	fmt::print("Nenne deinen Namen Held: ");
	std::cin >> name;
	fmt::print("Und so beginnt das Abenteuer von {}\n\n",name);
	std::cin.get();
	std::cin.get();

	m_player = std::make_shared<Player>(name);
	//start();
	test();
}

Adventure::~Adventure() = default;

void Adventure::test() {

	///*
	// test armor and equippedArmor
    std::shared_ptr<Item> testArmor = std::make_shared<Armor>(1,"BasicHelm",1,"helmet",3);
    testArmor->info();

	m_player->addItem(testArmor);
	m_player->equipArmor(testArmor);
	 //*/

	///*
	// test show functions
	m_player->info();

	m_player->showInventory();
	//*/

	/*
	// test if Battle works as expected
	std::shared_ptr<Enemy> dummy1 = std::make_shared<Enemy>("Napstablock",35,2,2);
	std::shared_ptr<Enemy> dummy2 = std::make_shared<Enemy>("Mad dummy",55,0,20);

	auto temp = std::vector<std::shared_ptr<Enemy>>();
	temp.emplace_back(dummy1);
	temp.emplace_back(dummy2);

	Battle(m_player,temp);
	*/

	StarterArea grasslands("Grassland");
	Battle temp(m_player,grasslands.generateEnemies());
}

void Adventure::start() {

}


