#include "display/screens/edit.hpp"
#include "display/display.hpp"
#include "input.h"
#include "eeprom.h"
#include "lib/ssd1306.h"
#include <stdio.h>
#include <stdlib.h>

static uint16_t pow_ten[5] = {1, 10, 100, 1000, 10000};

uint8_t Edit::increment_value(void) {
	const uint16_t result = edit + scroll_val;
	if (result > Memory_GetMax(name) || result <= edit) {
		return 0;
	}
	edit = result;
	return 1;
}

uint8_t Edit::decrement_value(void) {
	const uint16_t result = edit - scroll_val;
	if (result < Memory_GetMin(name) || result >= edit) {
		return 0;
	}
	edit = result;
	return 1;
}

void Edit::update_value(void) {
	ssd1306_FillRectangle(30, 32, 127, 39, Black);
	ssd1306_SetCursor(30, 32);
	char buf[6];
	snprintf(buf, sizeof(buf), "%u", edit);
	ssd1306_WriteString(buf, Font_7x10, White);
}
void Edit::update_increment(void) {
	ssd1306_FillRectangle(84, 54, 127, 63, Black);
	ssd1306_SetCursor(84, 54);
	char buf[6];
	snprintf(buf, sizeof(buf), "%u", pow_ten[scroll]);
	ssd1306_WriteString(buf, Font_7x10, White);
}

Edit::Edit(Title *_title, enum Address _name) : Screen(_title), name(_name) {
	edit = 0;
	scroll = 0;
	scroll_val = 1;
}

void Edit::init(void) {
	drawTitle();
	edit = Memory_Read(name);
	update_value();
	ssd1306_SetCursor(0, 54);
	ssd1306_WriteString("Increment: x", Font_7x10, White);
	update_increment();
}

uint8_t Edit::loop(void) {
	if (Input_GetState (BtnUp)) {
		if (increment_value()) {
			update_value();
			return 1;
		}
	}
	if (Input_GetState (BtnDown)) {
		if (decrement_value()) {
			update_value();
			return 1;
		}
	}
	if (Input_GetState (BtnEnter)) {
		if (scroll == 4) {
			scroll = 0;
			scroll_val = 1;
		}else{
			scroll++;
			scroll_val = pow_ten[scroll];
			if (scroll_val > Memory_GetMax(name) - Memory_GetMin(name)) {
				scroll = 0;
				scroll_val = 1;
			}
		}
		update_increment();
		return 1;
	}
	return 0;
}

void Edit::close(void) {
	Memory_Write(name, edit);
	Memory_Evaluate();
}
