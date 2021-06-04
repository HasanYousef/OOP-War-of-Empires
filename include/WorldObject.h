#pragma once
#include "macros.h"
#include <SFML/Graphics.hpp>
#include "Textures.h"

class WorldObject {
public:
	WorldObject();
	WorldObject(const WorldObjectType&, const sf::	Vector2f&);
	WorldObject(const WorldObjectType&, const sf::Vector2f&, const int&);

	//---functions----------------------------
	void draw(sf::RenderWindow&) const;
	virtual sf::Vector2f get_position() const;
	virtual void set_position(const sf::Vector2f&);
	virtual const WorldObjectType& get_type() const;
	virtual void set_type(const WorldObjectType&);
	virtual int get_object_team() const;

	//---build-body-----------
	virtual sf::Sprite create() const;
private:
	WorldObjectType m_objectType;
	sf::Vector2f m_position;
	int m_objectTeam; // "1" - if on ally team, "-1" if on enemy team
};

