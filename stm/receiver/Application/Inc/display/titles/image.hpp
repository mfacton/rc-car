#ifndef INC_DISPLAY_TITLES_IMAGE_HPP_
#define INC_DISPLAY_TITLES_IMAGE_HPP_

#include "display/templates/title.hpp"
#include <inttypes.h>

class Image: public Title {
public:
	Image(const uint8_t* _data, uint8_t _width, uint8_t _height);

	Image(const Image&) = delete;
	Image& operator=(const Image&) = delete;

	void draw(void) override;

private:
	const uint8_t* data;
	uint8_t width;
	uint8_t height;
};

#endif
