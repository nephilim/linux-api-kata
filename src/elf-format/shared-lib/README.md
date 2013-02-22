## static way

* link to say_greeting.c shared library in static way
* `gcc ... -L. -lkorea -o greet.app`
* run
    - LD_LIBRARY_PATH or,
* -fPIC

## dynamic way

* dynamicload.c
* dlfcn.h `gcc -o ... -ldl`

## readelf *.app

* -s
    - .symtan + .dynsym
