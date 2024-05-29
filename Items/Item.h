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
    unsigned m_quantity;


public:
    Item();
    Item(unsigned id, std::string itemName, unsigned quantity);
    ~Item();

    unsigned getId();
    std::string getItemName();
    unsigned getQuantity();

    void setId(unsigned id);
    void setitemName(std::string &itemName);
    void setQuantity(unsigned quantity);

    // Outputs Item description on the terminal
    virtual void info();
};


#endif //MODERNGAME_ITEM_H
