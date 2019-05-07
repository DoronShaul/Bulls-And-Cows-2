#pragma once
#include <iostream>
#include "Guesser.hpp"
#include "calculate.hpp"
using namespace std;

namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
private:
  int *digitsComb;
  int *solution;
  int bullsIndex = 0;
  int prevBulls = 0;
  int index = 0;
  int digit = 0;
  string temp = "";
  int firstbulls = 0;
  bool bullsboolean = true;
  int countbulls = 0;
  int cowsIndex = 0;
  int cowValue =0  ;
  bool firstCow=true;
  bool cowChange=true;
  int digitCombIndex=0;
  bool cowStarted=true;


public:
  string guess() override;
  void startNewGame(uint codeLength) override;
};
} // namespace bullpgia