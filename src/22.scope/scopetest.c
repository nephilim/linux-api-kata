#include "dbg.h"
#include "scopetest.h"

int THE_SIZE = 1000;
int MAC_LUNCH = 3000;
static int THE_AGE = 38;

int get_age() 
{
    return THE_AGE;
}

void set_age(int age)
{
    THE_AGE = age;
}

int get_maclunchprice()
{
    return MAC_LUNCH;
}

void set_maclunchprice(int price)
{
    MAC_LUNCH = price;
}
