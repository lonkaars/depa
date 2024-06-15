#pragma once

#include <string>

//! Enum for signal values
enum SignalLevel {
	LOW,
	HIGH,
	UNDEFINED
};

namespace std {
	//! convert enum to string
	std::string to_string(SignalLevel level);
}

