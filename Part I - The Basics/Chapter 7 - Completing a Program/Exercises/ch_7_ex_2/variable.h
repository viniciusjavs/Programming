#ifndef VARIABLE_H
#define VARIABLE_H

#include "std_lib_facilities.h"

struct Variable {
    string name;
    double value;
    Variable(string n, double v) : name(n), value(v) {}
};

bool operator==(const Variable &lhs, const string &rhs)
{
    return lhs.name == rhs;
}

#endif /* VARIABLE_H */
