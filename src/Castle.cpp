#pragma once
#include "Castle.h"

//-------------------------------------------------
Castle::Castle(const sf::Vector2f& p,
	const int& objectTeam, const int& health)
	: LiveObject(p, objectTeam, health) {}

//-------------------------------------------------
//this func draw the object
void Castle::draw() const {
	Window::instance().get_window().draw(create());
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite Castle::create() const{
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_ui_texture(UITexture::Castle));
	result.setPosition(get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 

