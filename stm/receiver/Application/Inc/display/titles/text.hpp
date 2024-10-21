#ifndef INC_DISPLAY_TITLES_TEXT_HPP_
#define INC_DISPLAY_TITLES_TEXT_HPP_

#include "display/templates/title.hpp"

class Text: public Title {
public:
	Text(const char* _text);

	Text(const Text&) = delete;
	Text& operator=(const Text&) = delete;

	void draw(void) override;

private:
	const char* text;
};

#endif
