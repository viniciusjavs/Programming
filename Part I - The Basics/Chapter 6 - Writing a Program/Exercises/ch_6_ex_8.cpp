// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 17 Jan 2016
// Chapter 6, Exercise 8

/*
  Re-implementation of the little guessing game called "Bulls and Cows", using
  four letters rather than four digits
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
    constexpr int range_limit = 26; // [0..25]
    return fib() % range_limit + 97; // alphabet ascii
}

bool in_vector(char letter, vector<char> v)
/*
  Checks if letter is in vector of char
 */
{
    for (auto l : v)
        if (letter == l)
            return true;
    return false;
}

void check_input (string str)
/*
  Check if input string match with the games rules
*/
{
    int size = 4;
    const int number = str.size();
    if (number != size)
	error("Bad input for \"guess\"", " - so may letters");

    for (unsigned int i = 0; i < str.size() - 1; ++i)
        for (unsigned int j = i + 1; j < str.size(); ++j)
            if (str[i] == str[j])
                throw logic_error("Repeated number!");
}

int get_bulls(const string  guess, const vector<char> secret)
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

int get_cows(const string guess, const vector<char> secret)
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
{
    try {
        int seed;
        cout << "\"Bulls and Cows\" Game!\n"
             << "Please enter a integer \"seed\" to generate game randomness: "
                "\n";
        cin >> seed;
        if (!cin)
            error("Bad input for \"seed\"");
        initialize(seed);
        // generate secret
        vector<char> secret;
        secret.push_back(gen_number());
        constexpr int size = 4;
        for (int i = 0; i < size - 1; ++i) {
            int digit = gen_number();
            while (in_vector(digit, secret))
                digit = gen_number();
            secret.push_back(digit);
        }
	
        cout << "Enter your guess, a string of " << size
             << " distinct letters: \n";
	string str;
	cin >> str;
	if (!cin) error("Bad input for \"guess\"");
	check_input(str);
        int bulls = 0, cows = 0;
        bulls = get_bulls(str, secret);
        cows = get_cows(str, secret) - bulls;
        while (bulls != size) {
            cout << "Bulls: " << bulls << " Cows: " << cows << '\n';
            cout << "Enter your guess: ";
            cin >> str;
            if (!cin) error("Bad input for \"guess\"");
            check_input(str);
            bulls = get_bulls(str, secret);
            cows = get_cows(str, secret) - bulls;
        }
        cout << "You win!\n";
	cout << "Your guess: " << str << '\n';
	cout << "Secret: ";
        for (auto d : secret) cout << d;
	cout << '\n';
    }
    catch (logic_error &e) {
        cerr << "Error: " << e.what() << '\n';
    }
    catch (runtime_error &e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}
