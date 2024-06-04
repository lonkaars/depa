#pragma once

#include <iostream>
#include <istream>

using std::ostream;

class Parser {

  friend void operator >> (Parser& p, std::istream& filestream) {
    // cout assigned to another object mycout
    std::cout << "the file contains:\n" << filestream << std::endl;
    mycout << "Value of dx and dy are \n";
    mycout << d.dx << " " << d.dy;
  }
}
