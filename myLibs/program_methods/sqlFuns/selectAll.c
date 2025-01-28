#include "../../../includeMyLibs.h"

static int callbackForReadAll(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    printBold(" | ");
    for (i = 0; i < argc; i++)
    {
        printYellow(argv[i]);
        printBold(" | ");
    }
    printf("\n");
    printf("\n");
    return 0;
}

int selectALL(const char *mainPathDBfile)
{
    char sqlCommand[] = "SELECT * FROM account ;";
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

    rc = sqlite3_exec(db, sqlCommand, callbackForReadAll, 0, &zErrMsg);

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
