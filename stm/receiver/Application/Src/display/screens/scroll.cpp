#include "lib/ssd1306.h"
#include "display/templates/title.hpp"
#include "display/screens/scroll.hpp"
#include "display/display.hpp"
#include "bitmaps.h"
#include "input.h"

static uint8_t int_min(uint8_t a, uint8_t b) {
	return a < b ? a : b;
}

static uint8_t int_max(uint8_t a, uint8_t b) {
	return a > b ? a : b;
}

void Scroll::update_cursor(void) {
	ssd1306_FillRectangle(10, 16, 17, 63, Black);
	ssd1306_SetCursor(10, static_cast<uint8_t>(16 * (select - scroll + 1) + 6));
	ssd1306_WriteString(">", Font_7x10, White);
}
void Scroll::update_options(void) {
	for (uint8_t i = 0; i < int_min(3, option_count); i++) {
		ssd1306_FillRectangle(20, static_cast<uint8_t>(16 * (i + 1)), 127,
				static_cast<uint8_t>(16 * (i + 1) + 15), Black);
		ssd1306_SetCursor(20, static_cast<uint8_t>(16 * (i + 1) + 6));
		char buf[MAX_CHARACTERS];
		options[scroll + i]->draw(buf);
		ssd1306_WriteString(buf, Font_7x10, White);
	}
	if (option_count > 3) {
		ssd1306_DrawBitmap(122, 16, bm_scroll, 6, 48, White);
		//unit = 44/option_count
		//start = 18 + unit*scroll
		//end = 18 + unit*(scroll+3) - 1
		const uint8_t start = 18 + 44*scroll/option_count;
		const uint8_t end = 17 + 44*(scroll+3)/option_count;
		ssd1306_FillRectangle(124, start, 125, end, White);
	}
}

Scroll::Scroll(Title *_title, Option **_options, uint8_t _option_count) :
		Screen(_title), options(_options), option_count(_option_count) {
	scroll = 0;
	select = 0;
}
Scroll::~Scroll() {
	delete[] options;
}

void Scroll::init(void) {
	drawTitle();
	update_cursor();
	update_options();
}
uint8_t Scroll::loop(void) {
	if (Input_GetState(BtnUp)) {
		if (select == scroll && option_count > 3) {
			if (select == 0) {
				select = option_count - 1;
				scroll = int_max(2, select) - 2;
				update_cursor();
			} else {
				select--;
				scroll--;
			}
			update_options();
		} else {
			if (select == 0) {
				select = option_count - 1;
			} else {
				select--;
			}
			update_cursor();
		}
		return 1;
	}
	if (Input_GetState(BtnDown)) {
		if (select == scroll + 2 && option_count > 3) {
			if (select == option_count - 1) {
				select = 0;
				scroll = 0;
				update_cursor();
			} else {
				select++;
				scroll++;
			}
			update_options();
		} else {
			if (select == option_count-1) {
				select = 0;
			}else{
				select++;
			}
			update_cursor();
		}
		return 1;
	}
	if (Input_GetState(BtnEnter)) {
		if (options[select]->press()) {
			ssd1306_SetCursor(20,
					static_cast<uint8_t>(16 * ((select - scroll) + 1) + 6));
			char buf[MAX_CHARACTERS];
			options[select]->draw(buf);
			ssd1306_WriteString(buf, Font_7x10, White);
			return 1;
		}
	}
	return 0;
}

void Scroll::close(void) {
	scroll = 0;
	select = 0;
}
