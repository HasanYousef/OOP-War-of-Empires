#pragma once
#include "macros.h"
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Window.h"
#include "Levels.h"

class WorldObject {
public:
	WorldObject(const sf::Vector2f&);
	WorldObject(const sf::Vector2f&, const bool&);

	//---functions----------------------------
	sf::Vector2f get_position() const;
	void set_position(const sf::Vector2f&);
	bool get_object_team() const;

	//---build-body-----------
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const = 0;
protected:
	sf::Vector2f m_position;
	bool m_objectTeam; // "true" - if on ally team, "false" if on enemy team
};

