#pragma once

#include "UIObject.h"

UIObject::UIObject(sf::Vector2f position) :
	m_position(position)
{}

void UIObject::draw() const {
	(Window::instance().get_window())->draw(create());
}

sf::Sprite UIObject::create(UITexture type) const {
	sf::Sprite obj = sf::Sprite(*(Textures::instance().get_ui_texture(type)));
	obj.setPosition({ m_position.x, m_position.y });
	return obj;
}
