#ifndef __EXECUTE_SQL_H__
#define __EXECUTE_SQL_H__

int execute_sql(char* datafile, char* sql, int (*xCallback)(void*, int, char**, char**));

#endif
