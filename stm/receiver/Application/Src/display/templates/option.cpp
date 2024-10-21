#include "display/templates/option.hpp"

Option::Option(const char *_text) : text(_text) {}

const char* Option::getText(void) {
	return text;
}
