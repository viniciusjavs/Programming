// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 29, 2016
// Chapter 5, Exercise 9

/*
  Program to read and store a series of N integers and then compute the sum of
  the first N integers. All inputs and outputs needs be handled.
 */

#include "std_lib_facilities.h"

int main()
{
    vector<int> ints;
    int n;
    long sum = 0;
    cout << "Please enter the number of values you want to sum: " << '\n';
    cin >> n;
    if (!cin) error("Error: invalid input for 'number of values'");
    cout << "Please enter some integers (press '|' to stop): " << '\n';
    for (int i; cin >> i;) {
        ints.push_back(i);
        if (ints.size() <= n) sum += i;
    }
    char eof;
    if (!cin) {
        cin.clear();
        cin >> eof;
        if (eof != '|') error("Error: invalid input for 'some integers'");
    }
    try {
        narrow_cast<int>(sum); // check if result can be expressed as an int
    }
    catch (runtime_error &e) {
        cerr << "Error: " << e.what() << '\n';
        cerr << "The result can't be expressed as an int" << '\n';
        return 1;
    }
    cout << "The sum of the first " << n << " numbers ( ";
    for (auto i : ints) cout << i << ' ';
    cout << ") is " << sum << '\n';
    if (ints.size() > n) error("Error: you insert so many numbers");
}
