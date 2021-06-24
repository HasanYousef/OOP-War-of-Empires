#pragma once
#include "GunFire.h"

GunFire::GunFire(const sf::Vector2f& p, const bool& objectTeam)
	: AnimatedObject(p, objectTeam), m_activated(std::make_shared<bool>(false)),
	m_animation(std::make_shared<FireAnimation>()) {}

void GunFire::activate() const {
	*m_activated = true;
	Sounds::instance().getSound(SoundType::ShootSoundEffect)->play();
}
void GunFire::disActivate() const {
	*m_activated = false;
	m_animation->setAnim();
}

//-------------------------------------------------
//this func draw the object
void GunFire::draw(float f) const {
	if (*m_activated) {
		Window::instance().getWindow()->draw(create(f));
		if (m_animation->getCurrFrame() == 9)
			disActivate();
	}
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite GunFire::create(float f) const {
	auto result = sf::Sprite(*(m_animation->getTexture()));

	m_animation->update(f);

	result.setPosition(WorldObject::getPosition());
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}