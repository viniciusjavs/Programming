// Copyright (C) 2016 vjavs
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: Jan. 17, 2016
// Chapter 6, Exercise 8

/*
  Re-implementation of the little guessing game called "Bulls and Cows" (Chapter
  5, Exercise 12/13), using four letters rather than four digits
 */

#include "std_lib_facilities.h"

bool in_vector(char letter, vector<char> v)
/*
  Checks if letter is in vector of char
 */
{
    for (auto l : v)
        if (letter == l) return true;
    return false;
}

vector<char> str_to_v(const string str)
/*
  Receives a string and returns a vector with each character of this string
  Check if input string match with the games rules
*/
{
    for (auto c : str)
        if (c < 'a' || c > 'z')
            error("Bad input for \"guess\"", " - illegal characters");

    int size = 4;
    if (str.size() != size)
        error("Bad input for \"guess\"", " - out of change letters");

    vector<char> guess;
    for (auto c : str)
        if (in_vector(c, guess))
            throw logic_error("Repeated number!");
        else
            guess.push_back(c);
    return guess;
}

vector<char> set_string()
/*
  Function that read "string" from user input.
  Wrapper for function str_to_v() that handles repeated numbers.
 */
{
    string str;
    cin >> str;
    if (!cin) error("Bad input for \"guess\"");
    vector<char> guess;
    try {
        guess = str_to_v(str);
    }
    catch (logic_error &e) {
        cerr << "Error: " << e.what() << '\n' << "Try again: ";
        guess = set_string();
    }
    return guess;
}

int get_bulls(const vector<char> guess, const vector<char> secret)
/*
  Returns the number of matching numbers by position
 */
{
    int bulls = 0;
    for (int i = 0; i < secret.size(); ++i)
        if (guess[i] == secret[i]) ++bulls;
    return bulls;
}

int get_cows(const vector<char> guess, const vector<char> secret)
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
    int seed;
    cout << "\"Bulls and Cows\" Game!\n"
            "Please enter a integer \"seed\" to generate game randomness: \n";
    cin >> seed;
    if (!cin) error("Bad input for \"seed\"");
    seed_randint(seed);

    // generate secret
    vector<char> secret;
    secret.push_back(randint('a', 'z')); // alphabet ascii
    constexpr int size = 4;
    for (int i = 0; i < size - 1; ++i) {
        int letter = randint('a', 'z');
        while (in_vector(letter, secret)) letter = randint('a', 'z');
        secret.push_back(letter);
    }

    cout << "Enter your guess, a string of " << size << " distinct letters: \n";
    vector<char> guess = set_string();
    int bulls = 0, cows = 0;
    bulls = get_bulls(guess, secret);
    cows = get_cows(guess, secret) - bulls;
    while (bulls != size) {
        cout << "Bulls: " << bulls << " Cows: " << cows << '\n';
        cout << "Enter your guess: ";
        guess = set_string();
        bulls = get_bulls(guess, secret);
        cows = get_cows(guess, secret) - bulls;
    }

    // print result
    cout << "You win!\n";
    cout << "Your guess: ";
    for (auto l : guess) cout << l;
    cout << "\nSecret: ";
    for (auto l : secret) cout << l;
    cout << '\n';
}
catch (runtime_error &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
