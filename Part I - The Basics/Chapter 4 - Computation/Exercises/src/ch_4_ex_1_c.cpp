// Copyright (C) 2016 Vjavs
// Author: Vinicius Sa (viniciusjavs@gmail.com)
// Timestamp: Sept. 9
// Chapter 4, Exercise 1
// Try This - pag. 111

/*
  Program that writes a table of characters with
  their corresponding integers values.
*/

#include "std_lib_facilities.h"

int main()
{
    int i{0};

    while (i < 26) {
        cout << char('a' + i) << '\t' << 'a' + i << '\n';
        ++i;
    }
}
