//Copyright 2016 Vinicius Sa (viniciusjavs@gmail.com)
//Chapter 4, Exercise 10
/*
 * Program that plays the game "Rock, Paper, Scissors",
 * A.K.A, jan-ken-pon
*/

#include "std_lib_facilities.h"
#include <limits>

// WELL512 PRNG - Pseudorandom number generator
constexpr int state_sz = 16;
vector<unsigned int> state(state_sz);
int idx = 0;

void init_well_rng_512(unsigned int seed)
/*
 * Initialize state to random bits
 * Reset idx to zero
*/
{
  seed %= numeric_limits<unsigned int>::max() + 1 - state_sz;
  for (int i = 0; i < state_sz; ++i) state[i] = seed + i;
  idx = 0;
}

unsigned int well_rng_512()
/*
 * Return 32 bit random number
*/
{
  unsigned int a, b, c, d;
  a = state[idx];
  c = state[(idx+13)&15];
  b = a^c^(a<<16)^(c<<15);
  c = state[(idx+9)&15];
  c ^= (c>>11);
  a = state[idx] = b^c;
  d = a^((a<<5)&0xDA442D24);
  idx = (idx +  15)&15;
  a = state[idx];
  state[idx] = a^b^d^(a<<2)^(b<<18)^(c<<28);
  return state[idx];
}

int main()
{
  constexpr unsigned int limit_range {100'000'000u};
  cout << "Jan-Ken-Pon Game!\n"
       << "For the game randomness choose a number between 0 and "
       <<  (numeric_limits<unsigned int>::max() + 1 - state_sz) / limit_range << '\n';
  unsigned int seed;
  cin >> seed;
  init_well_rng_512(seed); //seed prng
  vector<char> options = {'r', 'p', 's'};
  int u_points = 0, c_points = 0;
  cout << "Choose between Rock, Paper or Scissors: ('r', 'p', 's')\n";
  char u_opt;
  while (cin >> u_opt) {
    char c_opt = options[well_rng_512() % options.size()]; // computer game
    bool u_win = false; // means computer wins.
    if (u_opt != c_opt)
      switch (u_opt) {
      case 'r':
	if (c_opt == 's') u_win = true;
	break;
      case 'p':
	if (c_opt == 'r') u_win = true;
        break;
      case 's':
	if (c_opt == 'p') u_win = true;
        break;
      default:
	cout << "Error: invalid option '" << u_opt << "'\n";
        break;
      }
    if (u_opt == 'r' || u_opt == 'p' || u_opt == 's' ) {
      string res = "Computer wins!";
      if (u_win) {
	  res =  "You win!";
	  ++u_points;
      }
      else if (u_opt != c_opt) ++c_points;
      else res = "A tie";
      cout << "Computer: " << c_opt << '\n'
	   << "You: " << u_opt << '\n'
	   << res << '\n'
	   << "Computer: " << c_points << " points  vs "
	   << " You: "<< u_points << " points.\n";
    }
    cout << "Choose between Rock, Paper or Scissors: ('r', 'p', 's')\n";
  }
}
