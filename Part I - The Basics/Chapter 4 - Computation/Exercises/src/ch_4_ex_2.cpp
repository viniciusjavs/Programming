// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 23
// Chapter 4, Exercise 2

/*
  Program that computes the mean and median temperatures of a vector.
*/

#include "std_lib_facilities.h"

int main()
{
    vector<double> temps;           // temperatures
    for (double temp; cin >> temp;) // read into temp
        temps.push_back(temp);      // put temp into vector

    // compute mean temperature:
    double sum = 0;
    for (double temp : temps) sum += temp;
    cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute median temperature:
    sort(temps); // sort temperatures
    cout << "Median temperature: ";
    if (temps.size() % 2) // if size becomes odd
        cout << temps[temps.size() / 2];
    // if size becomes even
    else
        // mean of middle terms
        cout << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2;
    cout << '\n';
}
