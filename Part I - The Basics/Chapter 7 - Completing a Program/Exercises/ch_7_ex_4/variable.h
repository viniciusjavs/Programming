#ifndef VARIABLE_H
#define VARIABLE_H

#include "std_lib_facilities.h"

struct Variable {
    string name;
    double value;
    bool cnst;
    Variable(string n, double v, bool c = false)
        : name(n), value(v), cnst(c)
    {
    }
};

#endif /* VARIABLE_H */