#include "db_layer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mock structure representing an actual database handler (e.g., sqlite3*)
struct DBConnection {
    char database_name[256];
    int is_connected;
};

DBConnection* init_database(const char* db_name) {
    printf("[C DB] Initializing connection to engine: %s\n", db_name);
    DBConnection* conn = (DBConnection*)malloc(sizeof(DBConnection));
    if (conn) {
        strncpy(conn->database_name, db_name, 255);
        conn->is_connected = 1;
    }
    return conn;
}

int execute_insert_user(DBConnection* conn, const char* username, const char* email) {
    if (!conn || !conn->is_connected) return 0;
    
    // Low-level formatted query execution
    printf("[C DB] Executing query: INSERT INTO users (username, email) VALUES ('%s', '%s');\n", username, email);
    return 1; // Return success status
}

void close_database(DBConnection* conn) {
    if (conn) {
        printf("[C DB] Safely closing database connection storage.\n");
        conn->is_connected = 0;
        free(conn);
    }
}
