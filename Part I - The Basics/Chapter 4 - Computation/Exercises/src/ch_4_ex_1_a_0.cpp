//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 105
/*
 * Program that converts yen, kroner and pounds
 * into dollars.
 * Use suffixs 'y', 'k' or 'p' to indicate 
 * the unit of the input, any other suffix is an error
*/
#include "std_lib_facilities.h"
int main()
{
  constexpr long double yen_per_dollar {102.291326L};
  constexpr long double kroner_per_dollar {6.61143911L};
  constexpr long double pound_per_dollar {0.751851434L};
  double ammount {1};
  char unit {'?'};

  cout << "Please enter a value followed by a monetary unit (y, k or p):\n";
  while (cin >> ammount >> unit)
    if (unit == 'y')
      cout << ammount << "yen == " << ammount / yen_per_dollar << "dollars\n";
    else if (unit == 'k')
      cout << ammount << "kroner == " << ammount / kroner_per_dollar
	   << "dollars\n";
    else if (unit == 'p')
      cout << ammount << "pounds == " << ammount / pound_per_dollar
	   << "dollars\n";
    else
      cout << "Sorry, I don't support this kind of a unit, called "
	   << unit << '\n' ;
}
