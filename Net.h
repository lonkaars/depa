#pragma once

#include "Observer.h"
#include "SignalLevel.h"

class Net : public Subject {
private:
	SignalLevel level = UNDEFINED;
public:
	Net() = default;
	virtual ~Net() = default;
	//! Updates level and notifies all attached observers (node)
	virtual void setLevel(SignalLevel);
	//! Returns level value
	virtual SignalLevel getLevel();
};


