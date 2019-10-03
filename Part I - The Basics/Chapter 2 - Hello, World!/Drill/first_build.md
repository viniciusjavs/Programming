### This shows the outputs of the first successful build of the book.
```
vinicius@localhost:~/Programming$ cat hello_world.cpp 
#include "std_lib_facilities.h"

int main() // C++ programs starts by executing the function main
{
  cout << "Hello, World!\n"; // output "Hello, World!"
  keep_window_open(); // wait for a character to be entered
  return 0;
}
```
```
vinicius@localhost:~/Programming$ cat makefile 
hello_world: hello_world.cpp
	clang++ -Wall -std=c++14 hello_world.cpp -o hello_world
```
```
vinicius@localhost:~/Programming$ make
clang++ -Wall -std=c++14 hello_world.cpp -o hello_world
In file included from hello_world.cpp:1:
./std_lib_facilities.h:107:8: warning: comparison of unsigned expression < 0 is always false [-Wtautological-compare]
                if (i<0||size()<=i) throw Range_error(i);
                    ~^~
./std_lib_facilities.h:113:8: warning: comparison of unsigned expression < 0 is always false [-Wtautological-compare]
                if (i<0||size()<=i) throw Range_error(i);
                    ~^~
2 warnings generated.
```