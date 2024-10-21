#include "main.h"
#include "input.h"
#include <string.h>

static uint8_t btn_state[4] = {0};
static uint8_t btn_latch[4] = {0};

uint8_t Input_GetState(enum Button btn) {
	const uint8_t val = btn_latch[btn];
	btn_latch[btn] = 0;
	return val;
}

void Input_TimerHandler(void) {
	uint8_t btn_current[4];
	btn_current[0] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
	btn_current[1] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);
	btn_current[2] = HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);
	btn_current[3] = HAL_GPIO_ReadPin(BTN4_GPIO_Port, BTN4_Pin);

	for (uint8_t i = 0; i < 4; i++) {
		btn_latch[i] = btn_latch[i] || (!btn_current[i] && btn_state[i]);
		btn_state[i] = btn_current[i];
	}
}
