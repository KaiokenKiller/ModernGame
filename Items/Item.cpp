//
// Created by aj on 15.05.24.
//

#include "Item.h"

Item::Item(unsigned int id, const std::string &itemName, unsigned int quantity, Tag tag) {
	m_id = id;
	m_itemName = itemName;
	m_quantity = quantity;
	m_tag = tag;
	m_tagMap = {{Tag::helmet , "helmet"},{Tag::torso,"torso"},{Tag::legs,"legs"},{Tag::gloves,"gloves"},{Tag::weapon,"weapon"}};
}

unsigned int Item::getId() const {
    return m_id;
}

std::string Item::getItemName() {
    return m_itemName;
}

unsigned int Item::getQuantity() const {
    return m_quantity;
}

Tag Item::getTag() {
    return m_tag;
}

std::string Item::getTagString() {
	return m_tagMap.at(m_tag);
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

void Item::setTag(Tag tag) {
    m_tag = tag;
}


