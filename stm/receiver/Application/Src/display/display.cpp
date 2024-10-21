#include "display/display.hpp"
#include "display/templates/screen.hpp"
#include "display/screens.hpp"
#include "input.h"
#include "lib/ssd1306.h"
#include <stdint.h>
#include "main.h"

static Screen *page_stack[DISPLAY_MAX_STACK];
static uint8_t stack_depth = 0;

static void display_init_page(void) {
	ssd1306_Fill(Black);
	page_stack[stack_depth]->init();
	ssd1306_UpdateScreen();
}

void Display_Redirect(enum ScreenName name) {
	stack_depth++;
	page_stack[stack_depth] = Screens_GetScreen(name);
	display_init_page();
}
void Display_Back(void) {
	page_stack[stack_depth]->close();
	if (stack_depth > 0) {
		delete(page_stack[stack_depth]);
		stack_depth--;
	}
	display_init_page();
}

extern "C" {
void Display_Init(void) {
	ssd1306_Init();
	page_stack[stack_depth] = Screens_GetScreen(ScrnMenu);
	display_init_page();
}
void Display_Update(void) {
	if (Input_GetState(BtnBack)) {
		Display_Back();
	}else{
		if (page_stack[stack_depth]->loop()) {
			ssd1306_UpdateScreen();
		}
	}
}
}
