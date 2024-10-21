#include "display/options/redirect.hpp"
#include "display/templates/option.hpp"
#include "display/display.hpp"
#include <string.h>

Redirect::Redirect(const char *_text, enum ScreenName _name) : Option(_text), name(_name){}

void Redirect::draw(char *buf) {
	strcpy(buf, getText());
}

uint8_t Redirect::press(void) {
	Display_Redirect(name);
	return 0;
}
