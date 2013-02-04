#include <stdlib.h>
#include "dbg.h"

int main(int argc, char** argv) 
{
    debug("hello %d", 3);
    if (argc > 1) {
        int err_no = atoi(argv[1]);
        printf("errno %d: %s\n", 
                err_no, 
                (err_no == 0 ? "None":strerror(err_no)));
    }
    return 0;
}
