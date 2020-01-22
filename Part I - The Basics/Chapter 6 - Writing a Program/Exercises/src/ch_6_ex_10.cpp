// Copyright (C) 2017 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Jan. 18, 2017
// Chapter Six, Exercise 10

/*
  Program that calculates permutations and combinations
 */

#include "std_lib_facilities.h"

unsigned long factorial(int x)
{
    if (x < 0) error("Bad input", "factorial");
    if (x == 0) return 1;
    unsigned long fac = 1;
    for (unsigned int i = x; i > 1; --i) narrow_cast<int>(fac *= i);
    return fac;
}

int permutation(int a, int b)
{
    if (a < b || a < 1 || b < 1) // double checks
        error("Bad input", "permutation");
    return factorial(a) / factorial(a - b);
}

int combination(int a, int b)
{
    if (a < b || a < 1 || b < 1) // double checks
        error("Bad input", "combination");
    return permutation(a, b) / factorial(b);
}

int main()
try {
    cout << "Please Enter two numbers: \n";
    int a, b;
    cin >> a >> b;
    if (!cin) error("Bad input", "two numbers");
    cout << "Type 'p' for permutation or 'c' for combination: \n";
    char ans;
    cin >> ans;
    if (!cin) error("Bad input", "answer");
    int res = 0;
    switch (ans) {
    case 'p':
        res = permutation(a, b);
        break;
    case 'c':
        res = combination(a, b);
        break;
    default:
        error("Bad input", "answer");
    }
    cout << "Result is: " << res << '\n';
    return 0;
}
catch (runtime_error &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
