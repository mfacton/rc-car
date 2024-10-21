#ifndef INC_DISPLAY_OPTIONS_TOGGLE_HPP_
#define INC_DISPLAY_OPTIONS_TOGGLE_HPP_

#include "display/templates/option.hpp"
#include "eeprom.h"
#include <inttypes.h>

class Toggle: public Option {
public:
	Toggle(const char *_text, enum Address _name);

	void draw(char *buf) override;
	uint8_t press(void) override;

private:
	enum Address name;
};

#endif
