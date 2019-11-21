// Copyright (C) 2017 vjvas
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Jan. 11, 2017
// Chapter 5, Exercise 13

/*
  Implementation of a little guessing game called "Bulls and Cows".
  Use "randint()" instead of "fib()"  to generate random numbers
 */

#include "std_lib_facilities.h"

bool in_vector(int digit, vector<int> v)
/*
  Checks if digit is in vector
 */
{
    for (auto d : v)
        if (digit == d) return true;
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
        if (guess[i] == secret[i]) ++bulls;
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
            if (g == s) ++cows;
    return cows;
}

int main()
try {
    cout << "\"Bulls and Cows\" Game!\n";
    char ans = 1;
    while (ans) {
        cout << "Please enter a integer \"seed\" to generate game "
                "randomness: \n";
        int seed;
        cin >> seed;
        if (!cin) error("Bad input for \"seed\"");
        seed_randint(seed);

        // generate secret
        vector<int> secret;
        constexpr int max = 9; // randint range [0..9]
        secret.push_back(randint(max));
        constexpr int size = 4;
        for (int i = 0; i < size - 1; ++i) {
            int digit = randint(max);
            while (in_vector(digit, secret)) digit = randint(max);
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

        // play again?
        cout << "\nWould you like to play again?(y/n)\n";
        cin >> ans;
        if (!cin) error("Bad input for \"ans\"");
        if (ans == 'n')
            ans = 0;
        else if (ans == 'y')
            ans = 1;
        else
            error("Bad input for \"ans\"");
    }
}
catch (runtime_error &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
