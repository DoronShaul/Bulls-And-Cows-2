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
  virtual void startNewGame(uint codeLength) { this->length = codeLength;}
  void learn(string reply)
  {
    string numOfBulls = reply.substr(0, 1);   //substring the reply's string to be the bulls only.
    string numOfCows = reply.substr(2);       //substring the reply's string to be the cows only.
    this->bulls = stoi(numOfBulls);      //parsing the string to an int.
    this->cows = stoi(numOfCows);        //parsing the string to an int.
  }
};
} // namespace bullpgia