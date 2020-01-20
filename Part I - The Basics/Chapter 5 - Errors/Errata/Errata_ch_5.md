- Add the following to ```std_lib_facilities.h```:
```
inline void seed_randint(int seed) { default_random_engine engine(seed); }
```
