//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ADVENTURE_H
#define MODERNGAME_ADVENTURE_H
#include "Characters/Player.h"
#include <chrono>
#include <thread>


class Adventure {
private:
    std::shared_ptr<Player> m_player;


public:
    Adventure();

    ~Adventure() = default;

    void start();
    void test();
	static void displayText(std::vector<std::string>& text);
};


#endif //MODERNGAME_ADVENTURE_H
