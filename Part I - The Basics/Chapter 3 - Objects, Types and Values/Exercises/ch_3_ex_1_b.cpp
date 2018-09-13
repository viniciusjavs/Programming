//Chapter 3, Exercise 1
//Try this from page 68
/*
 * Program to exercise operators from page 67.
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Please enter a floating-point value:\n";
  int n; //modified later
  cin >> n;
  cout << "n == " << n
       << "\nn+1 == " << n + 1
       << "\nthree times n == " << 3 * n
       << "\ntwice n == " << n + n
       << "\nn squared == " << n * n
       << "\nhalf of n == " << n / 2;
  double n_double = n;
  cout << "\nsquare root of n == " << sqrt(n_double)
       << '\n';
}
