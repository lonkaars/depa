#include "Net.h"

Net::Net(){}

Net::~Net(){}

void Net::setLevel(SignalLevel level){
   this->level = level;
}
SignalLevel Net::getLevel(){
   return this->level;
}
