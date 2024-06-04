#pragma once
#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"



class Gate: Observer {
   protected:
      std::string label;
      std::string type;

      std::vector<Net*> inputs;
      Net* output;

   public:
      Gate(/* args */);
      virtual ~Gate();
      void update();
      virtual void addInput(Net*);
      virtual void setOutput(Net*);
      virtual void compare() = 0;
};

class GateAnd: public Gate {
   public:
      GateAnd(){};
      ~GateAnd(){};
      void compare();
};
