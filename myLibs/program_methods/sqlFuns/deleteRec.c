#include "../../../includeMyLibs.h"

// UPDATE table_name SET column1 = value1, column2 = value2...., columnN = valueN WHERE [condition];
void setSqlCommandDelete(char *dest, const char *ID)
{

    stringConcat(dest, "DELETE FROM account WHERE ID =  ", dest, RECORD_SIZE_SQL);
    stringConcat(dest, ID, dest, RECORD_SIZE_SQL);
    stringConcat(dest, " ;", dest, RECORD_SIZE_SQL);
}



int deleteRec(const char *mainPathDBfile, const char *ID)
{

    char sqlCommand[RECORD_SIZE_SQL] = {0};

    setSqlCommandDelete(sqlCommand, ID);

    printf("%s\n", sqlCommand);

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open(mainPathDBfile, &db);

    if (rc)
    {
        printRed("Can't open database\n");
        sqlite3_close(db);

        return MYMSG_DB_ERROR;
    }

    rc = sqlite3_exec(db, sqlCommand, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        printRed("\nsql error\n");
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return MYMSG_DB_ERROR;
    }

    printGreen(">> account deleted successfully: ");
    printGreen(ID);
    printGreen("\n");

    sqlite3_close(db);
    return MYMSG_DB_SUCCESS;
}
