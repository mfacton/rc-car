#ifndef INC_DISPLAY_SCREENS_HPP_
#define INC_DISPLAY_SCREENS_HPP_

#include "display/templates/screen.hpp"

enum ScreenName {
	ScrnMenu,
};

Screen* Screens_GetScreen(enum ScreenName name);

#endif
