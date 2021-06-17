#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Textures.h"

class Animation {
public:
	virtual std::shared_ptr <sf::Texture> get_texture() const = 0;
	bool update(float);
	int getCurrFrame();

protected:
	float m_totalTime = 0;
	int m_currFrame = 0;
};
