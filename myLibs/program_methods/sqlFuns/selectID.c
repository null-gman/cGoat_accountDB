#include "../../../includeMyLibs.h"

static int callbackForReadForID(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s | ", argv[i]);
    }
    printf("\n");
    return 0;
}

int selectID(const char *mainPathDBfile, const char *ID)
{
    char sqlCommand[RECORD_SIZE_SQL] = {0};

    stringConcat(sqlCommand, "SELECT * FROM account WHERE ID = ", sqlCommand, RECORD_SIZE_SQL);
    stringConcat(sqlCommand, ID, sqlCommand, RECORD_SIZE_SQL);
    stringConcat(sqlCommand, " ;", sqlCommand, RECORD_SIZE_SQL);

    // printf("%s\n", sqlCommand);

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(mainPathDBfile, &db);

    if (rc)
    {
        printRed(">> Can't open database\n");
        sqlite3_close(db);
        return MYMSG_DB_ERROR;
    }

    rc = sqlite3_exec(db, sqlCommand, callbackForReadForID, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        printRed(">> SQL error\n");
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return MYMSG_DB_ERROR;
    }

    printGreen(">> end\n");
    sqlite3_close(db);

    return MYMSG_DB_SUCCESS;
}
