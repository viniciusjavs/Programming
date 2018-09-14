// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 31 Dec 2016
// Chapter 5, Exercise 12

/*
  Implementation of a little guessing game called "Bulls and Cows"
 */

#include "std_lib_facilities.h"

int fib()
/*
  Returns the next element of the Fibbonacci series
 */
{
    static int a = 1;
    static int b = 1;
    int n = a + b;
    if (b < a) n = 1; // overflow
    a = b;
    b = n;
    return n;
}

void initialize(const int seed)
/*
  Use the seed to initialize the Fibbonacci series
 */
{
    for (int i = 0; i < abs(seed) % 9; ++i) // [1..8]
        fib();
}

int gen_number()
/*
  Generates a non predictable number between a specific range
 */
{
    constexpr int range_limit = 10; // [0..9]
    return fib() % range_limit;
}

bool in_vector(int digit, vector<int> v)
/*
  Checks if digit is in vector
 */
{
    for (auto d : v)
        if (digit == d)
            return true;
    return false;
}

vector<int> int_to_v(int number)
/*
  Receives an integer and returns a vector with each digit of this number
*/
{
    int size = 4;
    int digit;
    vector<int> guess;
    if (number > pow(10, size) - 1 ||
        number < pow(10, size - 2)) // [100..9999] are valid
        error("Bad input for \"guess\"", " - out of range number");
    if (number < pow(10, size - 1)) { // means [0100..0999]
        --size;
        guess.push_back(0);
    }
    for (int i = size - 1; i >= 0; --i) {
        digit = number / pow(10, i);
        if (in_vector(digit, guess))
            throw logic_error("Repeated number!");
        else
            guess.push_back(digit);
        number %= int(pow(10, i));
    }
    return guess;
}

vector<int> set_number()
/*
  Function that read "number" from user input.
  Wrapper for function int_to_v() that handles repeated numbers.
 */
{
    int number;
    cin >> number;
    if (!cin) error("Bad input for \"guess\"");
    vector<int> guess;
    try {
        guess = int_to_v(number);
    }
    catch (logic_error &e) {
        cerr << "Error: " << e.what() << '\n' << "Try again: ";
        guess = set_number();
    }
    return guess;
}

int get_bulls(vector<int> guess, vector<int> secret)
/*
  Returns the number of matching numbers by position
 */
{
    int bulls = 0;
    for (int i = 0; i < secret.size(); ++i)
        if (guess[i] == secret[i])
            ++bulls;
    return bulls;
}

int get_cows(vector<int> guess, vector<int> secret)
/*
  Returns the number of matching numbers between vectors
 */
{
    int cows = 0;
    for (int g : guess)
        for (int s : secret)
            if (g == s)
                ++cows;
    return cows;
}

int main()
try {
    int seed;
    cout << "\"Bulls and Cows\" Game!\nPlease enter a integer \"seed\" to "
            "generate game randomness: \n";
    cin >> seed;
    if (!cin) error("Bad input for \"seed\"");
    initialize(seed);

    // generate secret
    vector<int> secret;
    secret.push_back(gen_number());
    constexpr int size = 4;
    for (int i = 0; i < size - 1; ++i) {
        int digit = gen_number();
        while (in_vector(digit, secret))
            digit = gen_number();
        secret.push_back(digit);
    }

    cout << "Enter your guess, an integer of " << size
         << " distinct numbers: \n";
    vector<int> guess = set_number();
    int bulls = 0, cows = 0;
    bulls = get_bulls(guess, secret);
    cows = get_cows(guess, secret) - bulls;
    while (bulls != size) {
        cout << "Bulls: " << bulls << " Cows: " << cows << '\n';
        cout << "Enter your guess: ";
        guess = set_number();
        bulls = get_bulls(guess, secret);
        cows = get_cows(guess, secret) - bulls;
    }

    // print result
    cout << "You win!\n";
    cout << "Your guess: ";
    for (auto d : guess) cout << d;
    cout << "\nSecret: ";
    for (auto d : secret) cout << d;
    cout << '\n';
}
catch (runtime_error &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
