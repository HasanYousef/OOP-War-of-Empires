#pragma once
#include "Floor.h"

Floor::Floor(const sf::Vector2f& location) : WorldObject(location) {}

//-------------------------------------------------
//this func draw the object
void Floor::draw(float x) const {
	Window::instance().get_window()->draw(create(x));
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite Floor::create(float) const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_ui_texture(UITexture::Floor));
	result.setPosition(get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}