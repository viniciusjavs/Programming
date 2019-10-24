//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Drill 3
/*
 * Program that reads two ints continously into a while-loop
 * and prints the smaller and larger values, or if they are equals.
 * Entering '|' exits the program.
*/
#include "../../../include/std_lib_facilities.h"

int main()
{
  int a, b;
  while (cin >> a >> b) {
    if (a > b) {
      cout << "the smaller value is: " << b << '\n';
      cout << "the larger value is: " << a << '\n';
    }
    else if (b > a) {
      cout << "the smaller value is: " << a << '\n';
      cout << "the larger value is: " << b << '\n';
    }
    else
      cout << "the numbers are equals" << '\n';
  }
  
}
