//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Execise 16
/*
 * Program that finds the mode of a set of
 * positive integers.
*/
#include "std_lib_facilities.h"

int main()
{
  vector<unsigned int> numbers;
  for(unsigned int number; cin >> number;)
    numbers.push_back(number);
  sort(numbers); // contiguity of numbers
  unsigned int times = 0, max_times = 0, mode = 0;
  if (!numbers.empty()) mode = numbers.front();
  for (unsigned int i = 1; i < numbers.size(); ++i)
    if (numbers[i] == numbers[i-1]) {
      ++times;
      if (times > max_times) {
	max_times = times;
	mode = numbers[i];
      }
    }
    else
      times = 0;
  cout << mode << '\n';
}
