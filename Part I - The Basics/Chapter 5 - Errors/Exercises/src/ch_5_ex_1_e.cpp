// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 21 Dec 2016
// Chapter 5, Exercise 1, Try this from page 155

/*
  Showing logic error: snippet code for finding the lowest, highest, and average
  temperature values in a set of data.
 */

#include "std_lib_facilities.h"

int main()
{
    vector<double> temps; // temperatures

    for (double temp; cin >> temp;) // read and put into temps
        temps.push_back(temp);

    double sum = 0;
    double high_temp = 0;
    double low_temp = 0;

    for (int x : temps) {
	if(x > high_temp) high_temp = x; // find high
	if(x < low_temp) low_temp = x; // find low
	sum += x;
    }

    cout << "High temperature: " << high_temp << '\n'
	 << "Low temperature: " << low_temp << '\n'
	 << "Average temperature: " << sum/temps.size() << '\n';
}
