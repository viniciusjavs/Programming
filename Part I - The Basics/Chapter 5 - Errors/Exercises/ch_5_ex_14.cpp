// Copyright (C) 2017 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 11 Jan 2017
// Chapter 5, Exercise 14

/*
  Program that reads "day-of-the-week, value" pairs and print the values of each
  day-of-the-week vector and the sum of values in each vector. Ignore illegal
  days of the week but accept common synonyms. Print the number of rejected
  values.
 */

#include "std_lib_facilities.h"

int main()
{
    vector<int> sun;
    vector<int> mon;
    vector<int> tue;
    vector<int> wed;
    vector<int> thu;
    vector<int> fri;
    vector<int> sat;
    int illegal_days = 0;
    string day;
    int value;
    while (cin >> day >> value) {
        if (day == "sunday" || day == "Sunday" || day == "sun" || day == "Sun")
            sun.push_back(value);
        else if (day == "monday" || day == "Monday" || day == "mon" ||
                 day == "Mon")
            mon.push_back(value);
        else if (day == "tuesday" || day == "Tuesday" || day == "tue" ||
                 day == "Tue")
            tue.push_back(value);
        else if (day == "wednesday" || day == "Wednesday" || day == "wed" ||
                 day == "Wed")
            wed.push_back(value);
        else if (day == "thursday" || day == "Thursday" || day == "thu" ||
                 day == "Thu")
            thu.push_back(value);
        else if (day == "friday" || day == "Friday" || day == "fri" ||
                 day == "Fri")
            fri.push_back(value);
        else if (day == "saturday" || day == "Saturday" || day == "sat" ||
                 day == "Sat")
            sat.push_back(value);
        else
            ++illegal_days;
    }
    int sum = 0;
    for (auto v : sun) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;
    for (auto v : mon) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;
    for (auto v : tue) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;
    for (auto v : wed) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;
    for (auto v : thu) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;
    for (auto v : fri) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;
    for (auto v : sat) {
        cout << v << ' ';
        sum += v;
    }
    cout << "\nSum is: " << sum << '\n';
    sum = 0;

    cout << "Rejected values: " << illegal_days << '\n';
}
