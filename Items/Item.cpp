//
// Created by aj on 15.05.24.
//

#include "Item.h"

Item::Item() = default;

Item::Item(unsigned int id, std::string itemName, unsigned int quantity) {
    m_id = id;
    m_itemName = itemName;
    m_quantity = quantity;
}

Item::~Item() = default;

unsigned int Item::getId() {
    return m_id;
}

std::string Item::getItemName() {
    return m_itemName;
}

unsigned int Item::getQuantity() {
    return m_quantity;
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

void Item::info() {
    std::cout<< "ID: " << m_id << "\n Name: " << m_itemName << "\n Anzahl: " << m_quantity << std::endl;
}