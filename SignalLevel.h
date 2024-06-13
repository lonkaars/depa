#pragma once

#include <string>

enum SignalLevel {
	LOW,
	HIGH,
	UNDEFINED
};

namespace std {
	std::string to_string(SignalLevel level);
}

