//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Drill 8
/*
 * Program that reads one double continously into a while-loop
 * followed by a proper unit, that are "cm", "m", "in" or "ft".
 * Values with no unit or units other than the above will be rejected.
 * Entering "EOF" exits the program.
*/
#include "../../../include/std_lib_facilities.h"

int main()
{
  double d;
  string unit;
  constexpr double cm_per_m = 100;
  constexpr double cm_per_in = 2.54;
  constexpr double in_per_ft = 12;
  while (cin >> d >> unit) {
    if (unit == "cm") cout << '\'' << d << '\'' << " '" << unit << "'\n";
    else if (unit == "m") cout << '\'' << d << '\'' << " '" << unit << "'\n";
    else if (unit == "in") cout << '\'' << d << '\'' << " '" << unit << "'\n";
    else if (unit == "ft") cout << '\'' << d << '\'' << " '" << unit << "'\n";
    else
      cout << "Error: The unit: '" << unit << "' isn't allowed!\n";
  } 
}
