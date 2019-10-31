// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 30
// Chapter 4, Exercise 11

/*
  Program to find all the prime numbers
  between 1 and 100.
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
    for (int i = 3; i <= 100; ++i)
        if (is_prime(i)) primes.push_back(i);
    for (int prime : primes) cout << prime << " ";
    cout << '\n';
}
