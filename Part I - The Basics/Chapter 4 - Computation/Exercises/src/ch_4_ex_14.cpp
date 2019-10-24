//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 14
/*
 * Program to find prime numbers
 * between 1 and max, using
 * Sieve of Eratosthenes algorithm.
*/

#include "std_lib_facilities.h"

int main()
{
  cout << "Enter the max number for searching a range of primes:\n";
  int max;
  cin >> max;
  vector<char> sieve(max+1); // assume reverse logic
  for (int i = 2; i < sqrt(sieve.size()); ++i)
    if (!sieve[i])
      for (int j = i*i; j < sieve.size(); j+=i) sieve[j] = 1;
  for (int i = 2; i < sieve.size(); ++i)
    if (!sieve[i]) cout << i << ' ';
  cout << '\n';
}
