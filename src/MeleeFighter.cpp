#pragma once
#include "MeleeFighter.h"

MeleeFighter::MeleeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health, 
	const int& defaultAttack, const int& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth){
	AnimatedObject::reSetAnimationObject(FighterType::Tank2);
}


//-------------------------------------------------
void MeleeFighter::attack(const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {
	bool b1 = firstEnemy != NULL && create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds()) && firstEnemy->getHealth() > 0,
		b2 = firstEnemy == NULL && create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds());

	if (b1 || b2){
		if (getAnimationType() == AnimationType::Idle)
			setAnimationType(AnimationType::Attack);
		bool x = (AnimatedObject::getAnimationObject())->getCurrFrame() == DAMAGING_FRAME;
		if (getAnimationType() == AnimationType::Attack && x && m_attackClock.getElapsedTime().asSeconds() > 1.5*ANIMATION_SWITCH_TIME) {
			m_attackClock.restart();
			// attacking castle
			if (create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds()))
				enemyCastle->getDamaged(getDefaultAttack());
			else 
				if (! firstEnemy->getDamaged(getDefaultAttack())) {
					firstEnemy->setAnimationType(AnimationType::Die);
				}
		}
	}
	else if (getAnimationType() == AnimationType::Attack) {
		setAnimationType(AnimationType::Idle);
	}
}

//-------------------------------------------------
std::shared_ptr<bool> MeleeFighter::fullyDead() const{
	return Fighter::fullyDead();
}

//-------------------------------------------------
//this func draw the object
void MeleeFighter::draw(float f) const {
	Window::instance().get_window()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite MeleeFighter::create(float f) const {
	auto result = sf::Sprite(*(AnimatedObject::getAnimationObject())->get_texture() );
	if ((AnimatedObject::getAnimationObject())->update(f) != getAnimationType()) {
		if ((AnimatedObject::getAnimationObject())->update(0) == AnimationType::Idle && getAnimationType() == AnimationType::Die){
			setFullyDead();
		}
		(AnimatedObject::getAnimationObject())->set_anim_type(getAnimationType());
	}
	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 
/*
sf::Sprite MeleeFighter::create(float f, int) {
	auto result = sf::Sprite(*(AnimatedObject::getAnimationObject())->get_texture());
	if ((AnimatedObject::getAnimationObject())->update(0) == AnimationType::Idle && m_pre != AnimationType::Idle) {
		std::cout << "it returns idle i guess\n pre is:" << int(m_pre) << " | object anime is: " << int(getAnimationType()) << std::endl;
		if (int(m_pre) == int(AnimationType::Die)) {
			std::cout << "setting to dead\n";
			setFullyDead();
		}
	}
	savePre((AnimatedObject::getAnimationObject())->update(0));

	//std::cout << ((WorldObject::get_object_team()) ? "ally : " : "enemy : ") << LiveObject::getHealth() << std::endl;

	if ((AnimatedObject::getAnimationObject())->update(0) != getAnimationType()) {
		if (LiveObject::getHealth() <= 0 && (AnimatedObject::getAnimationObject())->update(0) == AnimationType::Idle) {
			std::cout << "reached fully dead";
			setFullyDead();
		}
		if ((AnimatedObject::getAnimationObject())->update(0) == AnimationType::Idle)
			std::cout << "it returns idle i guess\n";
		(AnimatedObject::getAnimationObject())->set_anim_type(getAnimationType());
	}
	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}*/