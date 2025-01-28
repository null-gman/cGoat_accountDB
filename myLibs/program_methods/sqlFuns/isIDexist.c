#include "../../../includeMyLibs.h"


// not working as expixted - do not use it
int isIDexist(const char *mainPathDBfile, char *ID)
{
    RECORD record;
    char sqlCommand[RECORD_SIZE_SQL] = {0};

    // "SELECT exists(SELECT 1 FROM users WHERE username = 'john_doe') AS row_exists;";
    // stringConcat(sqlCommand, "SELECT * FROM account WHERE ID = ", sqlCommand, RECORD_SIZE_SQL);

    stringConcat(sqlCommand, "SELECT * FROM account WHERE ID = ", sqlCommand, RECORD_SIZE_SQL);
    stringConcat(sqlCommand, ID, sqlCommand, RECORD_SIZE_SQL);
    stringConcat(sqlCommand, " ;", sqlCommand, RECORD_SIZE_SQL);

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open(mainPathDBfile, &db);
    printYellow(sqlCommand);
    if (rc)
    {
        printRed("Can't open database\n");
        sqlite3_close(db);
        return MYMSG_DB_ERROR;
    }

    rc = sqlite3_exec(db, sqlCommand, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        printRed(zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return MYMSG_FASLE;
    }

    printGreen(">> ID yes\n");
    sqlite3_close(db);
    return MYMSG_TRUE;

}
