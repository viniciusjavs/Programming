// Copyright (C) 2016 Vinicius Sa
// Author: Vinicius Sa <viniciusjavs@gmail.com>
// Timestamp: 22 Dec 2016
// Chapter 5, Exercise 7

/*
  Program to solve quadratic equation and detect when are no real roots
  Includes ability to check if solution is OK.
 */

#include "std_lib_facilities.h"

#include <limits>

double a, b, c; // globals

bool check_root(double root)
/*
  Function to check if given root is correct
 */
{
    constexpr double epsilon = numeric_limits<float>::epsilon();
    if (abs(a * root * root + b * root + c) - 0 > epsilon)
        return false;
    return true;
}

void quadratic_equation()
/*
  Function that prints the roots of quadratic equations
 */
{
    if (a == 0)
        error("This function is not quadratic");
    double d = 0;
    if (b == 0) { // means just calculate a sqrt
        d = -c / a;
        if (d == 0)
            cout << "The root of equation is: 0\n";
        else if (d < 0)
            error("The function has no real roots");
        else {
            cout << "The roots of equation are: " << sqrt(d) << " and "
                 << -sqrt(d) << '\n';
            if (!check_root(sqrt(d)) || !check_root(-sqrt(d)))
                error("wrong result!");
        }
    }
    else {
        double x1 = 0, x2 = 0;
        d = b * b - 4 * a * c;
        if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            cout << "The roots of equation are: " << x1 << " and " << x2
                 << '\n';
            if (!check_root(x1) || !check_root(x2))
                error("wrong result!");
        }
        else if (d < 0)
            error("The function has no real roots");
        else {
            cout << "The root of equation is: " << -b / 2 * a << '\n';
            if (!check_root(-b / 2 * a))
                error("wrong result!");
        }
    }
}

int main()
{
    cout << "Enter the terms 'a', 'b' and 'c' of quadratic equation:\n";
    cin >> a >> b >> c;
    try {
        quadratic_equation();
    }
    catch (runtime_error &e) {
        cerr << "runtime error: " << e.what() << '\n';
    }
}
