### Errata
#### Pg. 79
* Where you see:
    ``` char c2 = i1; ```
    It should be:
    ``` char c2 = i2; ```
    Working example:
    ```
    #include <iostream>
    int main()
    {
        char c = 'x';
        int i1 = c;
        int i2 = 'x';

        char c2 = i2;
        std::cout << c << ' ' << i1 << ' ' << c2 << '\n';
    }
    ```
    This will print:
    ``` x 120 x ```
