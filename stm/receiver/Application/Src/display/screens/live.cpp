#include "display/screens/live.hpp"
#include "lib/ssd1306.h"
#include <string.h>

Live::Live(Title *_title, Stream *_stream) : Screen(_title), stream(_stream) {}
Live::~Live(void) {
	delete(stream);
}

void Live::init(void) {
	drawTitle();
}
uint8_t Live::loop(void) {
	ssd1306_FillRectangle(0, 32, 127, 63, Black);
	stream->draw();
	return 1;
}

void Live::close(void) {}
