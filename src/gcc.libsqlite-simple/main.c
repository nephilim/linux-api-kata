#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <sqlite3.h>

#include "main.h"

struct globalArgs_t {
    char* datafile;     // -f/--file to name datafile 
    char* table;        // -t/--table  to name table
    char* name;         // --name 
    int age;            // --age
} globalArgs;

static const char *optString = "f:t:h?";

static const struct option longOpts[] = {
    { "name", required_argument, NULL, 0 },
    { "age", required_argument, NULL, 0 },
    { "help", no_argument, NULL, 'h'}
};


static int callback(void *NotUsed, int argc, char** argv, char **azColName) {
    int i;
    for(i=0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i]: "NULL");
    }
    printf("\n");
    return 0;
}

void display_usage( void )
{
    puts( "help") ;
    exit( EXIT_FAILURE );

}

int main(int argc, char* argv[]) 
{
    int opt=0;
    int longIndex = 0;
    
    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    while( opt != -1) {
        switch( opt ){
            case 'f':
                globalArgs.datafile = optarg;
                break;
            case 't':
                globalArgs.table = optarg;
                break;
            case 'h':   // fall-through intentionally
            case '?':
                display_usage();
                break;
            case 0:     // long option without any short arg
                if ( strcmp( "name", longOpts[longIndex].name ) == 0 ) {
                    globalArgs.name = optarg;
                }
                if ( strcmp( "age", longOpts[longIndex].name ) == 0 ) {
                    globalArgs.age = atoi(optarg);
                }
                break;
            default:
                // not supposed to be here
                break;
        }
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }

    // view mode
    if ( globalArgs.name == NULL || globalArgs.age == 0 ) {
        return show_table(
                globalArgs.datafile,
                globalArgs.table);
    } else {
        printf( "insert mode: name(%s), age(%d)\n", 
                globalArgs.name,
                globalArgs.age);
        //TODO: insert_table();
    }

    return 0;
}

int show_table(char* datafile, char* tablename)
{
    printf("view mode: file(%s) table(%s)\n", 
            datafile,
            tablename);

    // TODO: extract this using varargs
    // http://www.eskimo.com/~scs/cclass/int/sx11b.html
    char* sql;
    int size = snprintf(NULL, 0, SELECT_SQL, tablename);
    if( !(sql = malloc((size + 1) * sizeof(char))) ) {
        return EXIT_FAILURE;
    }
    snprintf(sql, size + 1, SELECT_SQL, tablename);
    
    return execute_sql(datafile, sql);
}

int execute_sql( char* datafile, char* sql )
{
    sqlite3* conn;
    int rc = sqlite3_open(datafile, &conn);
    if (rc) {
        fprintf(stderr, "Cannot open database\n");
        sqlite3_close(conn);
        return -1;
    }

    char* zErrMsg = 0;
    // TODO: callback signature extract
    // int (*xCallback)(void*, int, char**, char**));
    // http://www.sqlite.org/c_interface.html
    rc = sqlite3_exec(conn, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(conn);
    return 0;
}

