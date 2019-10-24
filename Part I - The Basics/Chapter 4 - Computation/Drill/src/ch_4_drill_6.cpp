//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Drill 6
/*
 * Program that reads one double continously into a while-loop
 * and keeps track the smallest and the largest value entered so far.
 * Then prints the values followed by 'smallest/largest so for' where applicable.
 * Entering '|' exits the program.
*/
#include "std_lib_facilities.h"

int main()
{
  double a;
  double smallest {1.7976931348623157E+308}; //biggest double number
  double largest {-1.7976931348623157E+308}; //smallest double number
  while (cin >> a) {
    if (a < smallest) {
      smallest = a;
      cout << smallest << " the smallest so far\n";
    }
    if (a > largest) {
      largest = a;
      cout << largest << " the largest so far\n";
    }
    if (a != smallest && a != largest)
      cout << a << '\n';
  } 
}
