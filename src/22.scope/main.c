#include <stdlib.h>
#include "scopetest.h"
#include "dbg.h"

int main(void)
{
    log_info("extern size: %d", THE_SIZE);
    log_info("mac lunch price: %d", get_maclunchprice());
    set_maclunchprice(5500);
    log_info("mac lunch price: %d", get_maclunchprice());
    log_info("age: %d", get_age());

    return EXIT_SUCCESS;
}
