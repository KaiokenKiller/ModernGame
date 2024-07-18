//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ITEM_H
#define MODERNGAME_ITEM_H
#include "iostream"
#include <fmt/printf.h>
#include "../Misc/Battle.h"

class Item {
protected:
    unsigned m_id;
    std::string m_itemName;
    unsigned m_quantity;
    std::string m_tag;


public:
    [[nodiscard]] unsigned getId() const;
    std::string getItemName();
    [[nodiscard]] unsigned getQuantity() const;
    std::string getTag();


    void setId(unsigned id);
    void setitemName(std::string &itemName);
    void setQuantity(unsigned quantity);
    void setTag(std::string &tag);

	// Defines how item reacts to being used
	virtual void use(Battle &battle) = 0;

    // Outputs Item description on the terminal
    virtual void info() = 0;
};


#endif //MODERNGAME_ITEM_H
