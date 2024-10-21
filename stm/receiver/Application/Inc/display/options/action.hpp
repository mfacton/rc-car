#ifndef INC_DISPLAY_OPTIONS_ACTION_HPP_
#define INC_DISPLAY_OPTIONS_ACTION_HPP_

#include <inttypes.h>
#include "display/templates/option.hpp"

class Action: public Option {
public:
	Action(const char* _text, void (*_fnc)(void));

	Action(const Action&) = delete;
	Action& operator=(const Action&) = delete;

	void draw(char *buf) override;
	uint8_t press(void) override;

private:
	void (*fnc)(void);
};

#endif
