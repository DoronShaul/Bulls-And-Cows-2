#include <iostream>
#include "SmartGuesser.hpp"
using namespace std;
using namespace bullpgia;

string SmartGuesser::guess()
{

    string ans = "";
    //חכם
    if (this->index == this->length) //we know all the digits of the chooser.
    {
        ////////////////bulls///////////////////

        if (bullsboolean == true)
        {
            this->firstbulls = this->bulls;
            bullsboolean = false;
        }

        if (this->firstbulls > 0 && countbulls < firstbulls) //if the handeling of the bulls isn't completed.
        {

            if (this->prevBulls == this->bulls + 1) //the right position of the bull
            {
                solution[bullsIndex - 1] = digitsComb[bullsIndex - 1];
                this->countbulls++;
            }
            temp = "";
            for (int i = 0; i < this->index; i++) //creating 'temp'
            {
                if (i == bullsIndex)
                {
                    temp += 'B';
                }
                else
                {
                    temp += to_string(this->digitsComb[i]);
                }
            }
            bullsIndex++;
            this->prevBulls = this->bulls; //updating the 'prevbulls' to the new 'bulls' value

            for (int i = 0; i < this->length; i++)
            {
                if (solution[i] == -1)
                {
                    cowValue = digitsComb[i];
                    cowsIndex = i;
                    digitCombIndex = cowsIndex;
                    cout << "first cowValue" << cowValue << endl;
                    break;
                }
            }

            cout << "temp bulls: " << temp << endl;
            return temp;
        }
        if (firstbulls == 0 && cowStarted == true)
        {
            cowStarted = false;
            cowValue = digitsComb[0];
            cowsIndex = 0;
            digitCombIndex = 0;
            cout << " cowValue no bulls" << cowValue << endl;
        }
        ////////////////cows///////////////////
        if (countbulls == firstbulls)
        {
            if (firstCow == true)
            {
                firstCow = false;
                this->bulls = 0;
            }
            if (this->bulls == 1) //if the cow became a bull
            {
                cout << "cowsIndex: " << cowsIndex << endl;
                solution[cowsIndex - 1] = cowValue;
                ////////
                for (int i = 0; i < this->length; i++)
                {
                    cout << "solution[i] " << solution[i] << endl;
                }

                ///swap
                int tempSwap = digitsComb[digitCombIndex];
                digitsComb[digitCombIndex] = digitsComb[cowsIndex - 1];
                digitsComb[cowsIndex - 1] = tempSwap;
                //end swap
                ///////
                for (int i = 0; i < this->length; i++)
                {
                    if (solution[i] == -1)
                    {

                        cowValue = digitsComb[i];
                        cowsIndex = i;
                        cout << "new cowValue" << cowValue << endl;
                        break;
                    }
                }
                for (int i = 0; i < this->length; i++)
                {
                    //cout<<digitsComb[i]<<",";
                }
                int counter = 0;
                int lastItemRemaining = 0;
                for (int i = 0; i < this->length; i++)
                {
                    if (solution[i] == -1)
                    {
                        counter++;
                    }
                }
                if (counter == 1)
                {
                    ans = "";
                    for (int j = 0; j < this->length; j++)
                    {
                        ans += to_string(digitsComb[j]);
                    }
                }

                for (int i = 0; i < this->length; i++)
                {
                    if (solution[i] == -1)
                    {
                        break;
                    }
                    if (i == this->length - 1)
                    {
                        ans = "";
                        for (int j = 0; j < this->length; j++)
                        {
                            ans += to_string(solution[j]);
                        }
                        delete[] digitsComb;
                        delete[] solution;
                        return ans;
                    }
                }
            }
            while (solution[cowsIndex] > -1 && cowsIndex < this->length)
            {
                cowsIndex++;
                cout << "cowsIndex: " << cowsIndex << endl;
            }
            temp = "";
            for (int i = 0; i < this->length; i++) //creating bulls string
            {
                if (solution[i] > -1)
                {
                    temp += 'B';
                }
                else if (i == cowsIndex)
                {
                    cowChange = false;
                    temp += to_string(cowValue);
                }
                else
                {
                    temp += 'C';
                }
            }
            if (cowChange == false)
            {
                cowsIndex++;
                cowChange = true;
            }
            cout << "temp cows: " << temp << endl;
            return temp;
        }
    }
    else //טיפש
    {
        if (this->bulls > 0)
        {
            for (int i = 0; i < bulls; i++) //inserts the digit to the answer's array.
            {
                this->digitsComb[this->index] = digit - 1;
                this->index++;
            }
        }
        if (this->index == this->length)
        {
            ans = "";
            for (int i = 0; i < this->index; i++)
            {
                ans += to_string(this->digitsComb[i]);
            }
            //delete[] this->digitsComb;
            return ans;
        }
        ans = "";
        for (int j = 0; j < this->length; j++)
        {
            ans += to_string(this->digit);
        }
        this->digit++;
        return ans;
    }
}

void SmartGuesser::startNewGame(uint codeLength)
{
    this->length = codeLength;
    this->bulls = 0;
    this->cows = 0;
    this->index = 0;
    this->digit = 0;
    this->bullsIndex = 0;
    this->prevBulls = 0;
    this->temp = "";
    this->digitsComb = new int[this->length];
    this->solution = new int[this->length];
    this->bullsboolean = true;
    this->firstCow = true;
    this->cowsIndex = 0;
    this->cowValue = 0;
    this->digitCombIndex = 0;
    this->firstbulls = 0;
    this->countbulls = 0;
    this->cowChange = true;
    this->cowStarted = true;
    for (int i = 0; i < this->length; i++)
    {
        solution[i] = -1;
    }
}
