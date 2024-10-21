#ifndef INC_DISPLAY_OPTIONS_REDIRECT_HPP_
#define INC_DISPLAY_OPTIONS_REDIRECT_HPP_

#include "display/templates/option.hpp"
#include "display/screens.hpp"
#include <inttypes.h>

class Redirect: public Option {
public:
	Redirect(const char* _text, enum ScreenName _name);

	void draw(char *buf) override;
	uint8_t press(void) override;

private:
	enum ScreenName name;
};

#endif
