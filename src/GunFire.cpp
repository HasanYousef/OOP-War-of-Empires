#pragma once
#include "GunFire.h"

GunFire::GunFire(const sf::Vector2f& p, const bool& objectTeam)
	: AnimatedObject(p, objectTeam, AnimationType::GunFire), m_activated(std::make_shared<bool>(false)) {}

void GunFire::activate() const{
	*m_activated = true;
}
void GunFire::disActivate() const{
	*m_activated = false;
	(AnimatedObject::getAnimationObject())->set_anim_type(AnimationType::GunFire);
}

//-------------------------------------------------
//this func draw the object
void GunFire::draw(float f) const {
	if (*m_activated) {
		Window::instance().get_window()->draw(create(f));
		if ((AnimatedObject::getAnimationObject())->getCurrFrame() == 9)
			disActivate();
	}
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite GunFire::create(float f) const {
	auto result = sf::Sprite(*(AnimatedObject::getAnimationObject())->get_texture());

	(AnimatedObject::getAnimationObject())->update(f);

	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}