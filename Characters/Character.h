//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_CHARACTER_H
#define MODERNGAME_CHARACTER_H
#include "iostream"
#include "vector"
#include "../Misc/Attack.h"


class Character{
protected:
    std::string m_name;
    int m_health;
    std::vector<Attack> m_attacks;



public:

    virtual void getDamaged(Attack attack);













    int getHealth() const;

    std::string getName() const;
};


#endif //MODERNGAME_CHARACTER_H
