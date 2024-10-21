#include "display/templates/screen.hpp"

Screen::Screen(Title *_title) : title(_title) {}

Screen::~Screen(void) {
	delete(title);
}

void Screen::drawTitle(void) {
	title->draw();
}
