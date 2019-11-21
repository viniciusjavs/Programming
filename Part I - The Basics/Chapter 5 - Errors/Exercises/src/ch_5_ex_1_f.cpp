// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Dec. 21
// Chapter 5, Exercise 1, Try this from page 156

/*
  Showing logic error - improved version - w/o error: snippet code for finding
  the lowest, highest, and average temperature values in a set of data.
 */

#include "std_lib_facilities.h"

int main()
{
    double sum = 0;
    double high_temp = -459.67; // initialize to max possibly low
                                // Absolute zero
    double low_temp{2.55e32};   // initialize to max possibly high
                                // Planck temperature
    int no_of_temps = 0;

    for (double temp; cin >> temp;) {           // read temp
        ++no_of_temps;                          // count temperatures
        sum += temp;                            // compute sum
        if (temp > high_temp) high_temp = temp; // find high
        if (temp < low_temp) low_temp = temp;   // find low
    }

    cout << "High temperature: " << high_temp << '\n'
         << "Low temperature: " << low_temp << '\n'
         << "Average temperature: " << sum / no_of_temps << '\n';
}
