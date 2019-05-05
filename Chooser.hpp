#pragma once
#include <iostream>
#include "calculate.hpp"
using namespace std;

namespace bullpgia
{
class Chooser
{
protected:
  string code;

public:
  Chooser() { this->code = ""; }
  Chooser(string givenCode) { this->code = givenCode; }
  virtual string choose(uint length) = 0;
};

} // namespace bullpgia