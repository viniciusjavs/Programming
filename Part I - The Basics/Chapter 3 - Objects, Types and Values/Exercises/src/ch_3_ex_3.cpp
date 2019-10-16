//Chapter 3, Exercise 3
//Vinicius Sa
/*
 * Program check react of compiler given use of keywords
*/
#include "std_lib_facilities.h"
int main()
{
  int while = 0;
  double d$ = 1;   //passed! but not recommended. why?
  char 1c = 'c';   //why is not the standard. The code will not be portable.
  string name = "vinicius";   //the standard is: a-z A-Z 0-9
  //the correct would be
  int loops = 0;
  double dS = 1.0;
  char c1 = 'c';
}
