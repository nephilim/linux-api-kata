#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    void (*greeting)();
    void* module;

    module = dlopen(argv[1], RTLD_LAZY);
    if (!module) exit(0);

    greeting = dlsym(module, "greet");
    printf("greeting: %p\n", greeting);
    if (greeting) {
        (*greeting)();
    }
    dlclose(module);
    return EXIT_SUCCESS;
}

