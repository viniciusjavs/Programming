#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "variable.h"

class Symbol_table {
    vector<Variable> names;

  public:
    bool is_declared(string);
    double define_name(string, double, bool = false);
    double set_value(string, double);
    double get_value(string);
};

#endif /* SYMBOL_TABLE_H */
