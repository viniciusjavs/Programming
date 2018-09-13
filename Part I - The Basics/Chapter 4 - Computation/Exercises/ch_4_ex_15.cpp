//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 15
/*
 * Program to find the first n prime numbers.
*/

#include "std_lib_facilities.h"

vector<int> primes = {2};

bool is_prime(int number)
{
  for (int prime : primes)
    if (!(number % prime)) return false;
  return true;
}

int main()
{
  cout << "Enter the number of primes that you request:\n";
  int number;
  cin >> number;
  if (number > 0) {
    for (int i = 3; primes.size() < number - 1; ++i) // '2' already in primes
      if (is_prime(i)) primes.push_back(i);
    cout << "1 "; // first prime number ever
    if (number > 1)
      for (int prime : primes) cout << prime << " ";
    cout << '\n';
  }
}
