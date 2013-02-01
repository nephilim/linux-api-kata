#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct _Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
} Address;

typedef struct _Database {
    Address rows[MAX_ROWS];
} Database;

typedef struct _Connection {
    FILE* file;
    Database* db;
} Connection;

void die(const char* message)
{
    if ( errno ) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(EXIT_FAILURE);
}

void print_address(Address* addr)
{
    printf("address(%d, %d)\nname: %s\nemail: %s",
            addr->id, addr->set,
            addr->name,
            addr->email);
}
void load_database(Connection* conn)                       // fread
{
    // fread doesn't handle eof, or error while read a file
    int rc = fread(conn->db, sizeof(Database), 1, conn->file);
    if (rc != 1) {
        die("Failed to load database");
    }
}

Connection* open_database(const char* filename, char mode)  // fopen
{
    Connection* conn  = malloc(sizeof(Connection));
    if(!conn) die("Memory allocation error:connection");

    conn->db = malloc(sizeof(Database));
    if(!conn->db) die("Memory allocation error:database");

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
        if(conn->file) {
            load_database(conn);
        }
    }
    if(!conn->file) die("Memory allocation error:file");
    return conn;
}

void close_database(Connection* conn)                      // fclose
{
    if(conn) {
        // fclose
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void write_database(Connection* conn)                      // rewind, fwrite, fflush
{
    // rewind == fseek(stream, 0L, SEEK_SET);
    // except that the error indicator is aloso cleared.
    rewind(conn->file);

    // fwrite = buffer write, needs fflush
    int rc = fwrite(conn->db, sizeof(Database), 1, conn->file);
    if(rc != 1) die ("Failed to write database");

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database");
}

void create_database(Connection* conn)
{
    int i = 0;
    for (i = 0; i < MAX_ROWS; i++) {
        Address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
    }
}

void set_database(Connection* conn, int id, const char* name, const char* email)
{
    Address* addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first");
    
    addr->set = 1;
    // bug: 
    char* res = strncpy(addr->name, name, MAX_DATA);
    if(!res) die("Copy name failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Copy email failed");
}

void get_database(Connection* conn, int id)
{
    Address* addr = &conn->db->rows[id];
    if (addr->set) {
        print_address(addr);
    } else {
        die("ID is not set");
    }
}

void delete_database(Connection* conn, int id)
{
    Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void list_database(Connection* conn)
{
    int i = 0;
    Database* db =  conn->db;

    for(i = 0; i < MAX_ROWS; i++ ) {
        Address* cur = &db->rows[i];

        if(cur->set) {
            print_address(cur);
        }
    }
}

int main(int argc, char** argv) 
{
    if(argc < 3) {
        const char* msg_format =  "USAGE: %s <dbfile> <action> [action params]";
        int size = snprintf(NULL, 0, msg_format, argv[0]);
        char* msg;
        if(!(msg = malloc((size + 1) * sizeof(char)))) {
            printf("argument failure");
            return EXIT_FAILURE;
        }
        snprintf(msg, size, msg_format, argv[0]);
        die(msg);
    }

    //
    char* filename = argv[1];
    char action = argv[2][0];
    Connection* conn = open_database(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(id >= MAX_ROWS) die("Too big record index");

    switch(action) {
        case 'c':
            create_database(conn);
            write_database(conn);
            break;
        case 'g':
            if (argc != 4) die("Need an id to get");

            get_database(conn, id);
            break;
        case 's':
            if (argc != 6) die("write id, name, email to set");
            set_database(conn, id, argv[4], argv[5]);
            write_database(conn);
            break;

        case 'd':
            if (argc != 4) die("Need id to delete");

            delete_database(conn,id);
            write_database(conn);
            break;
        case 'l':
            list_database(conn);
            break;
        default:
            die("Invalid action");
    }

    close_database(conn);
    return EXIT_SUCCESS;
}
