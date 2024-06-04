#include "Gate.h"

#include <iostream>

Gate::Gate(){}
Gate::~Gate(){}
void Gate::addInput(Net* net){
   net->attach(this);
}
void Gate::setOutput(Net* net){
   this->output = net;
}

void Gate::update(){
   std::cout << "updated" << std::endl;
   this->compare();
}

/*/ Concrete Gates: /*/

void GateAnd::compare(){
   SignalLevel new_out = HIGH;

   // TODO fix segfault somewhere below
   // for (int i = 0; i < this->inputs.size(); i++){
   //    switch (this->inputs[i]->getLevel()){
   //    case LOW:
   //       new_out = LOW;
   //       break;
   //    case HIGH:
   //       continue;
   //       break;
   //    case UNDEFINED:
   //    default:
   //       new_out = UNDEFINED;
   //       exit;
   //       break;
   //    }
   // }

   // if (this->output->getLevel() == new_out){
   //    /* do nothing */
   // } else {
   //    this->output->setLevel(new_out);
   // }

}
