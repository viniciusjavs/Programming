//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 3, Exercise 11
/*
 * Program that prompts the user to enter some number of pennies (1-cent coin),
 * nickels (5-cent), dimes (10-cent), quarters (25-cent), half-dollars (50-cent)
 * and one-dollar (100-cent) then print out the it plus total ammount properly.
*/
#include "std_lib_facilities.h"
int main()
{
  cout << "How many pennies do you have: \n";
  int pennies;
  cin >> pennies;
  cout << "How many nickels do you have: \n";
  int nickels;
  cin >> nickels;
  cout << "How many dimes do you have: \n";
  int dimes;
  cin >> dimes;
  cout << "How many quarters do you have: \n";
  int quarters;
  cin >> quarters;
  cout << "How many half dollars do you have: \n";
  int half_dollars;
  cin >> half_dollars;
  cout << "How many one-dollar do you have: \n";
  int one_dollar;
  cin >> one_dollar;
  cout << "You have " << pennies; if (pennies > 1) cout << " pennies.\n"; else cout << " pennie.\n";
  cout << "You have " << nickels; if (nickels > 1) cout << " nickels.\n"; else cout << " nickel.\n";
  cout << "You have " << dimes; if (dimes > 1) cout << " dimes.\n"; else cout << " dime.\n";
  cout << "You have " << quarters; if (quarters > 1) cout << " quarters.\n"; else cout << " quarter.\n";
  cout << "You have " << half_dollars; if (half_dollars > 1) cout << " half dollars.\n"; else cout << " half dollar.\n";
  double sum =  one_dollar * 100 + half_dollars * 50 + quarters * 25 + dimes * 10 + nickels * 5 + pennies;
  cout << "The total of all of yours coins is ";
  if (sum < 100)
    if (sum == 1)
      cout << sum << " cent.\n";
    else
      cout << sum << " cents.\n";
  else
    if (sum == 100)
      cout << sum / 100 << " dollar.\n";
    else
      cout << sum / 100 << " dollars.\n";
}
