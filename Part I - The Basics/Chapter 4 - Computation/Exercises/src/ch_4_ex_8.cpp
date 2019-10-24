//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 8
/*
 * How many squares are required to give
 * one mil, million and billion grains of rice?
*/

#include "std_lib_facilities.h"

int main()
{
  vector<unsigned long long int> quantitys
    { 1'000u,
      1'000'000u,
      1'000'000'000u };
  int square = 1;
  unsigned long long int grain = 1u, ammount = 1u;
  for (unsigned long long int quantity : quantitys) {
    for (;ammount < quantity; ++square, grain *= 2, ammount += grain) ;
      /*cout << "Square: " << square
	   << " Grains: " << grain
	   << " Ammount: " << ammount << '\n';*/
    cout << "Minimum squares to give " << quantity
	 << " grains is: " << square << '\n';
  }
}
