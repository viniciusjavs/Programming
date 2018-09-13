//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Execise 18
/*
 * Program that solves quadratic equations
*/
#include "std_lib_facilities.h"

int main()
{
  cout << "Enter the elements 'a', 'b' and 'c': \n";
  double a, b, c;
  cin >> a >> b >> c;
  double d = b*b - 4 * a * c;
  double x1 = (-b + sqrt(d)) / 2 * a;
  double x2 = (-b - sqrt(d)) / 2 * a;
  cout << "Roots are: " << x1 << ' ' << x2 << '\n';
}
