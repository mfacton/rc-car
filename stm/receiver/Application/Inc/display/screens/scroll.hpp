#ifndef INC_DISPLAY_SCREENS_SCROLL_HPP_
#define INC_DISPLAY_SCREENS_SCROLL_HPP_

#include <inttypes.h>
#include "display/templates/title.hpp"
#include "display/templates/screen.hpp"
#include "display/templates/option.hpp"

#define MAX_CHARACTERS 20

class Scroll: public Screen {
public:
	Scroll(Title *_title, Option **_options, uint8_t _option_count);
	~Scroll() override;

	Scroll(const Scroll&) = delete;
	Scroll& operator=(const Scroll&) = delete;

	void init(void) override;
	uint8_t loop(void) override;
	void close(void) override;

private:
	Option **options;
	uint8_t option_count;
	uint8_t scroll;
	uint8_t select;

	void update_cursor(void);
	void update_options(void);
};

#endif
