//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 3, Exercise 10
/*
 * Program that takes an operation followed by two operands and outputs the result
 * valid opations are: = - * /
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Enter an operation (+, -, *, /) followed by two values: \n";
  string operation;
  double l_num, r_num;
  while (cin >> operation >> l_num >> r_num ) {
    if (operation == "+")
      cout << l_num + r_num << '\n';
    else if (operation == "-")
      cout << l_num - r_num << '\n';
    else if (operation == "*")
      cout << l_num * r_num << '\n';
    else if (operation == "/")
      if (r_num != 0)
	cout << l_num / r_num << '\n';
      else
	cout << "Division by zero!" << '\n';
    else
      cout << "Invalid operation: " << operation << '\n';
  }
}
