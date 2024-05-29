//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ITEM_H
#define MODERNGAME_ITEM_H
#include "iostream"
#include <fmt/printf.h>

class Item {
protected:
    unsigned m_id;
    std::string m_itemName;
    unsigned m_quantity;
    std::string m_tag;


public:

    unsigned getId();
    std::string getItemName();
    unsigned getQuantity();
    std::string getTag();


    void setId(unsigned id);
    void setitemName(std::string &itemName);
    void setQuantity(unsigned quantity);
    void setTag(std::string &tag);

    // Outputs Item description on the terminal
    virtual void info() = 0;
};


#endif //MODERNGAME_ITEM_H
