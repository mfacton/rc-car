#include "display/options/action.hpp"
#include "lib/ssd1306.h"
#include <string.h>

Action::Action(const char *_text, void (*_fnc)(void)) : Option(_text), fnc(_fnc) {}

void Action::draw(char *buf) {
	strcpy(buf, getText());
}

uint8_t Action::press(void) {
	(*fnc)();
	return 0;
}
