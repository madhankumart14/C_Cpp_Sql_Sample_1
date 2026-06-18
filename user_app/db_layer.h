#ifndef DB_LAYER_H
#define DB_LAYER_H

#ifdef __cplusplus
extern "C" {
#endif

// Opaque pointer structure to encapsulate DB connection context
typedef struct DBConnection DBConnection;

DBConnection* init_database(const char* db_name);
int execute_insert_user(DBConnection* conn, const char* username, const char* email);
void close_database(DBConnection* conn);

#ifdef __cplusplus
}
#endif

#endif // DB_LAYER_H
