// Copyright (C) 2017 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 11 Jan 2017

/*
  Program that reads "day-of-the-week, value" pairs and print the values of each
  day-of-the-week vector and the sum of values in each vector. Ignore illegal
  days of the week but accept common synonyms. Print the number of rejected
  values.
 */

#include "std_lib_facilities.h"

bool in_vector(string str, vector<string> v)
/*
  Checks if given string is in vector
 */
{
    for (auto s : v)
        if (str == s)
            return true;
    return false;
}

void print_v(vector<int> v)
/*
  Print vector of values
 */
{
    for (auto i : v)
	cout << i << ' ';
    cout << '\n';
}

int sum_v(vector<int> v)
/*
  Returns the sum of values
 */
{
    int sum = 0;
    for (auto i : v)
	sum += i;
    return sum;
}

int main()
{
    cout << "Please enter (day-of-the-week, value) pairs: (Terminate with \"NoName 0\")\n";
    string day;
    int value;
    const vector<string> sun = {"sunday", "Sunday", "sun", "Sun"};
    const vector<string> mon = {"monday", "Monday", "mon", "Mon"};
    const vector<string> tue = {"tuesday", "Tuesday", "tue", "Tue"};
    const vector<string> wed = {"wednesday", "Wednesday", "wed", "Wed"};
    const vector<string> thu = {"thursday", "Thursday", "thu", "Thu"};
    const vector<string> fri = {"friday", "Friday", "fri", "Fri"};
    const vector<string> sat = {"saturday", "Saturday", "sat", "Sat"};
    vector<int> sunday;
    vector<int> monday;
    vector<int> tuesday;
    vector<int> wednesday;
    vector<int> thursday;
    vector<int> friday;
    vector<int> saturday;
    int illegal_days = 0;
    cin >> day >> value;
    if (!cin) error("Bad input");
    while (day != "NoName" || value != 0) {
        if (in_vector(day, sun))
	    sunday.push_back(value);
	else if (in_vector(day, mon))
	    monday.push_back(value);
	else if (in_vector(day, tue))
	    tuesday.push_back(value);
	else if (in_vector(day, wed))
	    wednesday.push_back(value);
	else if (in_vector(day, thu))
	    thursday.push_back(value);
	else if (in_vector(day, fri))
	    friday.push_back(value);
	else if (in_vector(day, sat))
	    saturday.push_back(value);
	else
            ++illegal_days;
	cin >> day >> value;
	if (!cin) error("Bad input");
    }
    cout << "The values of the seven day-of-the-week vectors "
	 << "followed by the sum of the values are:\n";
    cout << "Sunday: "; print_v(sunday); cout << "Sum: " << sum_v(sunday) << '\n';
    cout << "Monday: "; print_v(monday); cout << "Sum: " << sum_v(monday) << '\n';
    cout << "Tuesday: "; print_v(tuesday); cout << "Sum: " << sum_v(tuesday) << '\n';
    cout << "Wednesday: "; print_v(wednesday); cout << "Sum: " << sum_v(wednesday) << '\n';
    cout << "Thursday: "; print_v(thursday); cout << "Sum: " << sum_v(thursday) << '\n';
    cout << "Friday: "; print_v(friday); cout << "Sum: " << sum_v(friday) << '\n';
    cout << "Saturday: "; print_v(saturday); cout << "Sum: " << sum_v(saturday) << '\n';
    cout << "The number of rejected values is: " << illegal_days << '\n';
}
