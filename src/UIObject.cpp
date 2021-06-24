#pragma once

#include "UIObject.h"

UIObject::UIObject(sf::Vector2f position) :
	m_position(position)
{}

void UIObject::draw() const {
	(Window::instance().getWindow())->draw(create());
}

sf::Sprite UIObject::create(UITexture type) const {
	sf::Sprite obj = sf::Sprite(*(Textures::instance().getUiTexture(type)));
	obj.setPosition({ m_position.x, m_position.y });
	return obj;
}
