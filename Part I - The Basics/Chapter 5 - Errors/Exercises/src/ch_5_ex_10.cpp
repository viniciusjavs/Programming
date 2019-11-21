// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 30, 2016
// Chapter 5, Exercise 10

/*
  Program to read and store a series of N floating point numbers, compute the
  sum of the first N numbers and then make a vector of the N-1 differences
  adjacent values. All inputs needs be handled.
 */

#include "std_lib_facilities.h"

int main()
{
    vector<double> numbers;
    vector<double> diffs;
    int n;
    double sum = 0;
    cout << "Please enter the number of values you want to sum: " << '\n';
    cin >> n;
    if (!cin) error("Error: invalid input for 'number of values'");
    cout << "Please enter some floating point numbers  (press '|' to stop): "
         << '\n';
    for (double i; cin >> i;) {
        numbers.push_back(i);
        if (numbers.size() <= n) sum += i;
    }
    char eof;
    if (!cin) {
        cin.clear();
        cin >> eof;
        if (eof != '|')
            error("Error: invalid input for 'some floating point numbers'");
    }
    cout << "The sum of the first " << n << " numbers ( ";
    for (auto i : numbers) cout << i << ' ';
    cout << ") is " << sum << '\n';
    if (numbers.size() > n) error("Error: you insert so many numbers");
    for (int i = 0; i < numbers.size() - 1; ++i)
        diffs.push_back(numbers[i] - numbers[i + 1]);
    cout << "The differences between adjacent values are: ( ";
    for (auto i : diffs) cout << abs(i) << ' ';
    cout << ")." << '\n';
}
