#ifndef __MAIN_H__
#define __MAIN_H__

#define SELECT_SQL "select name, age from %s"
int main(int, char**);
void display_usage( void );
int show_table(char* datafile, char* table);
static int callback(void*, int, char**, char**);
int execute_sql( char* datafile, char* sql );
#endif
