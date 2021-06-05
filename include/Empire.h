#pragma once

#include<forward_list>
#include<memory>
#include "LiveAnimatedObject.h"
#include "Window.h"

class Empire {
public:
	void draw() const;

private:
	std::forward_list <std::shared_ptr <LiveAnimatedObject>> m_fighters;
};