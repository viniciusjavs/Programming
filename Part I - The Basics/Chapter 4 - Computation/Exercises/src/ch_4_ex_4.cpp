// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 23
// Chapter 4, Exercise 4

/*
  Program to play a numbers guessing game.
*/

#include "std_lib_facilities.h"

int main()
{
    int lowest = 0;
    int highest = 100;
    cout << "Thinks a number between " << lowest << " and " << highest << '\n';
    char ans = ' ';
    int guesses = 0;
    while (ans != 'e') {
        ++guesses;
        int middle = (lowest + highest) / 2;
        cout << "The number you are thinking is equal, less or greater than '"
             << middle << "'. ('e', 'l' or 'g')\n";
        cin >> ans;
        if (ans == 'l')
            highest = middle;
        else if (ans == 'g')
            lowest = middle;
        else if (ans == 'e')
            cout << "I won!!!\nNº guesses: " << guesses << '\n';
        else
            cout << "We don't know the option '" << ans << "'\n";
    }
}
