//Chapter 3, Exercise 2
//Vinicius Sa
/*
 * Program to convert miles to kilemeters
 * 1 mile = 1.60934 km
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "Enter the number of miles:\n";
  double distance;
  while (cin>>distance) {
    cout << distance << " mile(s) == " << distance * 1.60934
	 << " kilometers\n";
  }
}
