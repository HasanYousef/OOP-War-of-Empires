#pragma once
#include "GunFire.h"

GunFire::GunFire(const sf::Vector2f& p, const bool& objectTeam)
	: AnimatedObject(p, objectTeam), m_activated(std::make_shared<bool>(false)),
	m_animation(std::make_shared<FireAnimation>()) {}

void GunFire::activate() const {
	*m_activated = true;
}
void GunFire::disActivate() const {
	*m_activated = false;
	m_animation->set_anim();
}

//-------------------------------------------------
//this func draw the object
void GunFire::draw(float f) const {
	if (*m_activated) {
		Window::instance().get_window()->draw(create(f));
		if (m_animation->getCurrFrame() == 9)
			disActivate();
	}
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite GunFire::create(float f) const {
	auto result = sf::Sprite(*(m_animation->get_texture()));

	m_animation->update(f);

	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}