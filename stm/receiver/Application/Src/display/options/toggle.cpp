#include "display/options/toggle.hpp"
#include <stdio.h>
#include "eeprom.h"

Toggle::Toggle(const char *_text, enum Address _name) : Option(_text), name(_name){}

void Toggle::draw(char *buf) {
	sprintf(buf, "%s [%s]", getText(), Memory_Read(name) ? "EN" : "DS");
}

uint8_t Toggle::press(void) {
	Memory_Toggle(name);
	Memory_Evaluate();
	return 1;
}
