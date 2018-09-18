#ifndef TOKEN_H
#define TOKEN_H

#include "std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string str)
        : kind(ch), name(str) {} // first error caught by compiler.
};

#endif /* TOKEN_H */
