//Chapter 3, Exercise 1
//Try this from page 80
/*
 * Program safe/unsafe conversions
 * static-safe-type
*/
#include "std_lib_facilities.h"
int main()
{
  int a = 20000;
  //int a {20000};
  //const int a = 20000;
  //int a = 127;
  char c = a;  //try to squeeze a large int into a small char
  //char c {a};  //uniform universal initialization
  //char c = 20000;  //try to squeeze a large int literal into a small char
  //c = 20000;
  //c = a;
  //c = {a};  //assignment? initializer?
  int b = c;
  if (a != b)
    cout << "oops!: " << a << " != " << b << '\n';
  else
    cout << "Wow! We have large characters\n";
}
