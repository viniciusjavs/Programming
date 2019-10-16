//Chapter 3, Exercise 1
//Try this from page 65
/*
 * Program name and age from page 64.
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Please enter your first name and age:\n";
  string first_name;
  double age;
  cin >> first_name >> age;
  cout << "Hello, " << first_name << " (age  " << age * 12 << ")\n";
}
