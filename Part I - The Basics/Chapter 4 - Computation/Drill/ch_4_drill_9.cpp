//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Drill 9
/*
 * Program that reads one double continously into a while-loop
 * followed by a proper unit, that are "cm", "m", "in" or "ft".
 * Values with no unit or units other than the above will be rejected.
 * Then prints the smallest, largest, the number of values and the sum of them.
 * Entering "EOF" exits the program.
*/
#include "../../../include/std_lib_facilities.h"

int main()
{
  double value, value_in_m, sum = 0; // in meters
  int counter = 0;
  string unit;
  constexpr double cm_per_m = 100;
  constexpr double cm_per_in = 2.54;
  constexpr double in_per_ft = 12;
  double smallest {1.7976931348623157E+308}; //biggest double number
  double largest {-1.7976931348623157E+308}; //smallest double number
  while (cin >> value >> unit) {
    if (unit == "cm")
      value_in_m = value / cm_per_m;
    else if (unit == "m")
      value_in_m = value;
    else if (unit == "in")
      value_in_m = value * (cm_per_in / cm_per_m);
    else if (unit == "ft")
      value_in_m = value * (in_per_ft * (cm_per_in / cm_per_m));
    else
      cout << "Error: The unit: '" << unit << "' isn't allowed!\n";
    if ( unit == "cm" || unit == "m"  || unit == "in" ||  unit == "ft" ) {
      ++counter;
      cout << '\'' << value << '\'' << " '" << unit << "'\n";
      if (value_in_m < smallest)
	smallest = value_in_m;
      if (value_in_m > largest)
	largest = value_in_m;
      sum += value_in_m;
    }
  }
  cout << "Sum: " << sum << 'm' << '\n'
       << "Nº values: " << counter << '\n'
       << "Smallest value: " << smallest << "m\n"
       << "Largest value: " << largest << "m\n";
}
