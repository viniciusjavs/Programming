//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 1, Try This - pag. 109
/*
 * Program that converts yen, kroner, pounds,
 * yuan and real into dollars.
 * Use suffixs 'y', 'k', 'p', 'u' or 'r' to indicate 
 * the unit of the input, any other suffix is an error
*/
#include "std_lib_facilities.h"
int main()
{
  constexpr long double yen_per_dollar {102.291326L};
  constexpr long double kroner_per_dollar {6.61143911L};
  constexpr long double pound_per_dollar {0.751851434L};
  constexpr long double yuan_per_dollar {6.67775173L};
  constexpr long double real_per_dollar {3.2166442L};
  double ammount {1};
  char unit {'?'};

  cout << "Please enter a value followed by a monetary unit"
       << " (y, k, p, u or r):\n";
  while (cin >> ammount >> unit)
    switch (unit) {
    case 'y':
      cout << ammount << "yen == " << ammount / yen_per_dollar << "dollars\n";
      break;
    case 'k':
      cout << ammount << "kroner == " << ammount / kroner_per_dollar
	   << "dollars\n";
      break;
    case 'p':
      cout << ammount << "pounds == " << ammount / pound_per_dollar
	   << "dollars\n";
      break;
    case 'u':
      cout << ammount << "yuan  == " << ammount / yuan_per_dollar
	   << "dollars\n";
      break;
    case 'r':
      cout << ammount << "real  == " << ammount / real_per_dollar
	   << "dollars\n";
      break;
    default:
      cout << "Sorry, I don't support this kind of a unit, called '"
	   << unit << "'\n" ;
      break;
    }    
}
