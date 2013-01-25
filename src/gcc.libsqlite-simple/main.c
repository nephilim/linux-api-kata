#include <stdio.h>
#include <sqlite3.h>
#include "main.h"

#define TABLE_NAME "data.sqlite3"

int main(int argc, char* argv[]) 
{
    if ( argc == 1 ) {
        puts("view mode");
        return show_table(TABLE_NAME);
    }

    if ( argc != 2 ) {
        puts("The argments must be name(string) and age(int)");
        return -1;
    }


    return 0;
}

int show_table(char* table_name)
{
    printf("will show %s table\n",table_name);
   
    sqlite3* conn;
    int error = sqlite3_open(table_name, &conn);
    if (error) {
        puts("Cannot open database");
        return -1;
    }
    return 0;
}
