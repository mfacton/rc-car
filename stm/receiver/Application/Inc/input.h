#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include <inttypes.h>

enum Button {
	BtnUp,
	BtnDown,
	BtnEnter,
	BtnBack
};

#ifdef __cplusplus
extern "C" {
#endif
uint8_t Input_GetState(enum Button btn);
#ifdef __cplusplus
}
#endif

void Input_TimerHandler(void);

#endif
