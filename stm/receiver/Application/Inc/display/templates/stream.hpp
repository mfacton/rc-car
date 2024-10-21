#ifndef INC_DISPLAY_TEMPLATES_CHANNEL_HPP_
#define INC_DISPLAY_TEMPLATES_CHANNEL_HPP_

class Stream {
public:
	virtual ~Stream();

	virtual void draw(void) = 0;
};

#endif
