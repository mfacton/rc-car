#include "display/streams/print.hpp"
#include "lib/ssd1306.h"
#include <inttypes.h>
#include <string.h>

Print::Print(void (*_fnc) (char*)) : fnc(_fnc) {}

void Print::draw(void) {
	char buf[15];
	(*fnc)(buf);
	ssd1306_WriteStringCenter(buf, 32, Font_7x10, White);
}
