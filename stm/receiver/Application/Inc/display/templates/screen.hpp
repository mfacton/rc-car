#ifndef INC_DISPLAY_TEMPLATES_SCREEN_HPP_
#define INC_DISPLAY_TEMPLATES_SCREEN_HPP_

#include "display/templates/title.hpp"
#include <inttypes.h>

class Screen {
public:
	Screen(Title *_title);
	virtual ~Screen(void);

	Screen(const Screen&) = delete;
	Screen& operator=(const Screen&) = delete;

	virtual void init(void) = 0;
	virtual uint8_t loop(void) = 0;
	virtual void close(void) = 0;

	void drawTitle(void);

private:
	Title *title;
};

#endif
