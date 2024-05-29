#pragma once
#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"



class Gate: Observer {
   private:
      std::string label;
      std::string type;

      std::vector<Net*> inputs;
      std::vector<Net*> outputs;

   public:
      Gate(/* args */);
      ~Gate();
      virtual void addInput(Net*);
      virtual void addOutput(Net*);
};

class GateAnd
