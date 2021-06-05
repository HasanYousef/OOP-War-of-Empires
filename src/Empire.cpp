#pragma once

#include <Empire.h>

void Empire::draw() const {
	for (std::shared_ptr <LiveAnimatedObject> f : m_fighters) {
		(Window::instance().get_window())->draw(f->create());
	}
}

