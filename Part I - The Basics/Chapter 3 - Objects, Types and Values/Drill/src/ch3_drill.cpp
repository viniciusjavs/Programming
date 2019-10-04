// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 29 Aug 2016
// Chapter 3, Drill

/*
  A simple form letter based on user input.
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the pearson you want to write to:\n";
    string first_name;
    cin >> first_name;
    cout << "Dear, " << first_name << '\n'
         << "How are you? I'm fine.\n"
         << "I miss you.\n"
         << "I hope you are fine in yours studies "
         << "in Canada. I love you, son.\n";
    cout << "Enter the name of the another friend:\n";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";
    cout << "Please, enter 'm' if the friend is male or 'f' "
         << "if the friend is female:\n";
    char friend_sex{0};
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    else if (friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    cout << "Enter the age of the recipient:\n";
    int age;
    cin >> age;
    cout << "I hear you had a birthday and you are " << age << " years old.\n";
    if (age <= 0 || age >= 110)
        simple_error("you're kidding!");
    else if (age <= 12)
        cout << "Next year you're " << age + 1 << ".\n";
    else if (age == 17)
        cout << "Next year you will be able to vote.\n";
    else if (age >= 70)
        cout << "I hope you are enjoying retirement.\n";
    cout << "Yours sincerily,\n\n"
         << "Vinicius Sa\n";
}
