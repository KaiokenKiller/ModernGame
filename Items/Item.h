//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ITEM_H
#define MODERNGAME_ITEM_H
#include "iostream"

class Item {
protected:
    unsigned m_id;
    std::string m_itemName;
    unsigned quantity;


public:

    virtual void info();
};


#endif //MODERNGAME_ITEM_H
