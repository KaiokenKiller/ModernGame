//
// Created by aj on 15.05.24.
//

#include "Item.h"

unsigned int Item::getId() const {
    return m_id;
}

std::string Item::getItemName() {
    return m_itemName;
}

unsigned int Item::getQuantity() const {
    return m_quantity;
}

std::string Item::getTag() {
    return m_tag;
}

void Item::setId(unsigned int id) {
    m_id = id;
}

void Item::setitemName(std::string &itemName) {
    m_itemName = itemName;
}

void Item::setQuantity(unsigned int quantity) {
    m_quantity = quantity;
}

void Item::setTag(std::string &tag) {
    m_tag = tag;
}