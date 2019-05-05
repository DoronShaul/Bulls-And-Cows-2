#pragma once
#include <iostream>
#include "Guesser.hpp"
#include "calculate.hpp"
using namespace std;

namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
  public:
    string guess() override;
};
} // namespace bullpgia