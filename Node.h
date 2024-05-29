#pragma once
#include <string>
#include <vector>

#include "Observer.h"
#include "Net.h"



class Node: Observer {
   private:
      std::string label;
      std::string type;

      std::vector<Net*> inputs;
      std::vector<Net*> outputs;

   public:
      Node(/* args */);
      ~Node();
      virtual void addInput(Net*);
      virtual void addOutput(Net*);
};
