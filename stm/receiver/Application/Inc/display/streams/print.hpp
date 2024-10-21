#ifndef INC_DISPLAY_STREAMS_PRINT_HPP_
#define INC_DISPLAY_STREAMS_PRINT_HPP_

#include "display/templates/stream.hpp"

class Print: public Stream {
public:
	Print(void (*_fnc) (char*));

	void draw(void) override;

private:
	void (*fnc)(char*);
};

#endif
