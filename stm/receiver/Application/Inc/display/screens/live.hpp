#ifndef INC_DISPLAY_SCREENS_LIVE_HPP_
#define INC_DISPLAY_SCREENS_LIVE_HPP_

#include "display/templates/screen.hpp"
#include "display/templates/stream.hpp"

class Live: public Screen {
public:
	Live(Title *_title, Stream *_stream);
	virtual ~Live(void);

	Live(const Live&) = delete;
	Live& operator=(const Live&) = delete;

	void init(void) override;
	uint8_t loop(void) override;
	void close(void) override;

private:
	Stream *stream;
};

#endif
