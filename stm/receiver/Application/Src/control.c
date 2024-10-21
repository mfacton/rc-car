#include "control.h"
#include "eeprom.h"
#include "display/display.hpp"

void Control_Init(void) {
	Memory_Init();
	Display_Init();
}

void Control_Loop(void) {
	Display_Update();
}
