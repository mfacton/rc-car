#include "display/titles/text.hpp"
#include "lib/ssd1306.h"
#include <string.h>
#include <inttypes.h>

Text::Text(const char *_text) : text(_text) {}

void Text::draw(void) {
	ssd1306_WriteStringCenter(text, 0, Font_7x10, White);
}
