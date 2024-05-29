//
// Created by aj on 15.05.24.
//

#include "Adventure.h"

Adventure::Adventure() = default;

Adventure::~Adventure() = default;

void Adventure::test() {
    Armor* testArmor = new Armor(1,"BasicHelm",1,"helmet",10);
    testArmor->info();

}

void Adventure::start() {

}


