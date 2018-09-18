#include "symbol_table.h"

bool operator==(const Variable &lhs, const string &rhs)
{
    return lhs.name == rhs;
}

bool Symbol_table::is_declared(string s)
{
    return find(names.begin(), names.end(), s) != names.end();
}

double Symbol_table::define_name(string name, double val, bool is_const)
// Add {name, val} to var_table.
{
    if (is_declared(name)) error(name, " declared twice");
    names.push_back(Variable(name, val, is_const));
    return val;
}

double Symbol_table::set_value(string s, double d)
{
    for (auto &var : names)
        if (var.name == s) {
            if (var.cnst)
                /* Stroustrup style. Initialize, check modifiers or exceptions
                 * and finally go to the end of the function. He avoids the
                 * 'else' statement. */
                error("set: attempt to redefine a constant variable: ",
                      var.name);
            return var.value = d;
        }
    error("set: undefined name ", s);
    return 0; // This will never be reached!
}

double Symbol_table::get_value(string s)
{
    for (const auto &var : names)
        if (var.name == s) return var.value;
    error("get: undefined name ", s);
    return 0; // This should never be reached!
}
