#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include <inttypes.h>

enum Button {
	BtnUp,
	BtnDown,
	BtnStart,
	BtnStop
};

uint8_t Input_GetState(enum Button btn);

void Input_TimerHandler(void);

#endif
