//
// Created by aj on 15.05.24.
//

#include "Adventure.h"

Adventure::Adventure() = default;

Adventure::~Adventure() = default;

void Adventure::test() {
	Player* player = new Player("Hans");
    std::shared_ptr<Item> testArmor = std::make_shared<Armor>(1,"BasicHelm",1,"helmet",10);
    testArmor->info();

	player->addItem(testArmor);
	player->equipArmor(testArmor);

	player->info();

	player->showInventory();



}

void Adventure::start() {

}


