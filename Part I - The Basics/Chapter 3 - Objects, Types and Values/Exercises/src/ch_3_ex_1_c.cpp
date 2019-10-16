// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 1
// Try this from page 73

/*
  Program to detect repeated words.
*/

#include "std_lib_facilities.h"

int main()
{
    string previous = ""; // previous word initialized to "not a word"
    string current;       // current word
    stringstream test("She she laughed He He He because what he did did not "
                      "look very very good good");
    cout << test.str() << '\n';
    int count = 0;
    while (test >> current) {      // read a stream of words
        if (previous == current) { // check if the word is the same as last
            cout << "repeated word: " << current << '\n';
            ++count;
        }
        previous = current;
    }
    cout << "There was " << count << " repeated words.\n";
}
