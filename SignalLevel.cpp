#include "SignalLevel.h"

std::string std::to_string(SignalLevel level) {
	if (level == HIGH) return "HIGH";
	if (level == LOW) return "LOW";
	if (level == UNDEFINED) return "UNDEFINED";
	return "???";
}

