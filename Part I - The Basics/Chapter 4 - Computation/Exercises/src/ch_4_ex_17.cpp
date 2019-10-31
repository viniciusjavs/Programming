// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Oct. 04
// Chapter 4, Exercise 17

/*
  Program that finds the min, max and mode of a sequence of strings.
*/

#include "std_lib_facilities.h"

int main()
{
    vector<string> words;
    for (string word; cin >> word;) words.push_back(word);
    sort(words); // adjacent words
    unsigned int acc = 0, max = 0;
    string mode = "";
    if (!words.empty()) mode = words.front();
    for (unsigned int i = 1; i < words.size(); ++i)
        if (words[i] == words[i - 1]) {
            ++acc;
            if (acc > max) {
                max = acc;
                mode = words[i];
            }
        }
        else
            acc = 0;
    cout << "The min is: " << words.front() << '\n'
         << "The max is: " << words.back() << '\n'
         << "The mode is: " << mode << '\n';
}
