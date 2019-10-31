// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 23
// Chapter 4, Exercise 3

/*
  Program that reads a sequence of doubles into a vector, them computes and
  prints the sum, smallest, greatest and the mean of them.
*/

#include "std_lib_facilities.h"
#include <limits>

int main()
{
    vector<double> distances;
    double sum = 0;
    double smallest = numeric_limits<double>::max();
    double greatest = numeric_limits<double>::lowest();
    for (double distance; cin >> distance;) {
        distances.push_back(distance);
        sum += distance;
        if (distance < smallest) smallest = distance;
        if (distance > greatest) greatest = distance;
    }
    cout << "Total distance: " << sum << '\n'
         << "Smallest distance: " << smallest << '\n'
         << "Greatest distance: " << greatest << '\n'
         << "Average distance: " << sum / distances.size() << '\n';
}
