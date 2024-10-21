#include "display/titles/image.hpp"
#include "lib/ssd1306.h"

Image::Image(const uint8_t *_data, uint8_t _width, uint8_t _height) :
		data(_data), width(_width), height(_height) {
}

void Image::draw(void) {
	ssd1306_DrawBitmap(static_cast<uint8_t>((128 - width) / 2), static_cast<uint8_t>((16 - height) / 2), data, width,
			height, White);
}
