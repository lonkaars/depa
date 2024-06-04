#pragma once

#include "Observer.h"

enum SignalLevel {LOW, HIGH, UNDEFINED};

class Net: public Subject {
   private:
      SignalLevel level = UNDEFINED;
   public:
      Net(/* args */);
      ~Net();
      virtual void setLevel(SignalLevel);
      virtual SignalLevel getLevel();
};


