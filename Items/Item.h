//
// Created by aj on 15.05.24.
//

#ifndef MODERNGAME_ITEM_H
#define MODERNGAME_ITEM_H
#include "iostream"
#include <fmt/printf.h>

// every Tag must be mapped to string in Constructor
enum class Tag{helmet,torso,legs,gloves,weapon,healing,throwable,buffDamage};

class Item {
protected:
    unsigned m_id;
    std::string m_itemName;
    unsigned m_quantity;
    Tag m_tag;
	std::unordered_map<Tag,std::string> m_tagMap;
	Item(unsigned int id, const std::string &itemName, unsigned int quantity, Tag tag);

public:
    [[nodiscard]] unsigned getId() const;
    std::string getItemName();
    [[nodiscard]] unsigned getQuantity() const;
    Tag getTag();
	std::string getTagString();


    void setId(unsigned id);
    void setitemName(std::string &itemName);
    void setQuantity(unsigned quantity);
    void setTag(Tag tag);

    // Outputs Item description on the terminal
    virtual void info() = 0;


};


#endif //MODERNGAME_ITEM_H
