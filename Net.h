#pragma once

#include "Observer.h"
#include "SignalLevel.h"

class Net : public Subject {
private:
	SignalLevel level = UNDEFINED;
public:
	Net() = default;
	virtual ~Net() = default;
	virtual void setLevel(SignalLevel);
	virtual SignalLevel getLevel();
};


