// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 30
// Chapter 4, Exercise 12

/*
  Program to find all the prime numbers between 1 and max.
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
    int max;
    cout << "Enter the max number for searching a range of primes:\n";
    cin >> max;
    for (int i = 3; i <= max; ++i)
        if (is_prime(i)) primes.push_back(i);
    cout << "1 "; // first prime number ever.
    for (int prime : primes) cout << prime << " ";
    cout << '\n';
}
