//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 105
/*
 * Program to convert from inches to centimeters, 
 * or centimeters to inches.
 * A suffix 'i'  or 'c' indicates the unit of the input,
 * any other suffix is an error
*/
#include "std_lib_facilities.h"
int main()
{
  constexpr double cm_per_inch {2.54};
  double length {1.};
  char unit {'?'};

  cout << "Please enter a length followed by a unit (c or i):\n";
  while (cin >> length >> unit)
    if (unit == 'i')
      cout << length << "in == " << cm_per_inch * length << "cm\n";
    else if (unit == 'c')
      cout << length << "cm == " << length / cm_per_inch  << "in\n";
    else
      cout << "Sorry, I don't know a unit called " << unit << '\n' ;
}
