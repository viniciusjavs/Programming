// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Aug. 29, 2016
// Chapter 3, Exercise 2

/*
  Program to convert miles to kilometers(1 mile = 1.60934 km).
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the number of miles:\n";
    double distance;
    while (cin >> distance) {
        cout << distance << " mile(s) == " << distance * 1.60934
             << " kilometers\n";
    }
}
