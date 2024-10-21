#ifndef INC_DISPLAY_TEMPLATES_OPTION_HPP_
#define INC_DISPLAY_TEMPLATES_OPTION_HPP_

#include <inttypes.h>

class Option {
public:
	Option(const char *_text);

	Option(const Option&) = delete;
	Option& operator=(const Option&) = delete;

	virtual void draw(char *buf) = 0;
	virtual uint8_t press(void) = 0;

	const char* getText(void);
private:
	const char *text;
};

#endif
