#ifndef INC_DISPLAY_SCREENS_EDIT_HPP_
#define INC_DISPLAY_SCREENS_EDIT_HPP_

#include "display/templates/screen.hpp"
#include "eeprom.h"
#include <inttypes.h>

class Edit: public Screen {
public:
	Edit(Title *_title, enum Address _name);

	void init(void) override;
	uint8_t loop(void) override;
	void close(void) override;

private:
	enum Address name;
	uint16_t edit;
	uint8_t scroll;
	uint16_t scroll_val;

	uint8_t increment_value(void);
	uint8_t decrement_value(void);

	void update_value(void);
	void update_increment(void);
};

#endif
