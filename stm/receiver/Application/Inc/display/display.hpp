#ifndef INC_DISPLAY_DISPLAY_HPP_
#define INC_DISPLAY_DISPLAY_HPP_

#define DISPLAY_MAX_STACK 4

#ifdef __cplusplus

#include "display/screens.hpp"

void Display_Redirect(enum ScreenName name);
void Display_Back(void);

#endif

#ifdef __cplusplus
extern "C" {
#endif
void Display_Init(void);
void Display_Update(void);
#ifdef __cplusplus
}
#endif

#endif
