#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//using namespace bullpgia;

namespace bullpgia
{
//converting a given string to array
static int *stringToArray(const string &str)
{
    int stringLength = str.length();  //length of the string
    int *arr = new int[stringLength]; //array in the same length
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'B') //if this index is a 'bull'
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = str[i] - 48; //'-48' because of ascii code
        }
    }
    return arr;
}

//this method calculates the number of bulls and cows.
static string calculateBullAndPgia(const string choice, const string guess)
{
    string ans;
    int bulls = 0; //bulls
    int cows = 0;  //pgia
    if (choice.length() != guess.length())
    {
        return "chooser's and guesser's length does not match.";
    }
    else
    {
        int *chooserArr;
        int *guesserArr;

        chooserArr = stringToArray(choice); //coverting the choice's string to an int array.
        guesserArr = stringToArray(guess);  //coverting the guess's string to an int array.

        size_t size = choice.length();

        //searching bulls
        for (size_t i = 0; i < size; i++)
        {
            if (chooserArr[i] == guesserArr[i])
            {
                bulls++;
                chooserArr[i] = -1;
                guesserArr[i] = -1;
            }
        }

        //searching cows
        for (size_t i = 0; i < size; i++)
        {
            if (guesserArr[i] != -1)
            {
                for (size_t j = 0; j < size; j++)
                {
                    if (i != j && guesserArr[i] == chooserArr[j])
                    {
                        cows++;
                        chooserArr[j] = -1;
                        guesserArr[i] = -1;
                        break;
                    }
                }
            }
        }
        delete[] chooserArr;
        delete[] guesserArr;
    }
    string b = to_string(bulls);
    string c = to_string(cows);
    ans = b + "," + c;

    return ans;
}

} // namespace bullpgia