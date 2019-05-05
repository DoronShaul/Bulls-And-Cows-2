#pragma once
#include <iostream>
#include "calculate.hpp"
using namespace std;

namespace bullpgia
{
class Guesser
{
protected:
  string code;
  int bulls=0;
  int cows=0;

public:
  uint length;
  Guesser() { this->code = ""; }
  Guesser(string guessCode) { this->code = guessCode; }
  virtual string guess() = 0;
  void startNewGame(uint codeLength) { this->length = codeLength; }
  void learn(string reply)
  {
    string numOfBulls = reply.substr(0, 1);
    string numOfCows = reply.substr(2);
    this->bulls = stoi(numOfBulls);
    this->cows = stoi(numOfCows);
  }
};
} // namespace bullpgia