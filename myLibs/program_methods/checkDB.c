#include "../../includeMyLibs.h"

int createTableAccountInDB(const char *DB_FILE_PATH)
{

    char sqlCommand[] = "CREATE TABLE account ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "userName varchar(255),"
                        "email varchar(255) NOT NULL,"
                        "domain varchar(255) NOT NULL,"
                        "category varchar(255) NOT NULL,"
                        "password varchar(255) NOT NULL,"
                        "note varchar(255)"
                        ");";

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(DB_FILE_PATH, &db);

    if (rc)
    {
        // printf("Can't open database: %s\n", sqlite3_errmsg(db));
        printRed("\t- error with opening DB = 'FALSE'");
        sqlite3_close(db);
        return MYMSG_DB_ERROR;
    }

    rc = sqlite3_exec(db, sqlCommand, NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        printRed("\t- SQL error = 'FALSE'");
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return MYMSG_DB_ERROR;
    }

    sqlite3_close(db);
    return MYMSG_DB_SUCCESS;
}

int checkDB(const char * DB_FILE_PATH)
{
    printYellow("- checking for DB ...\n");

    if (isFileExist(DB_FILE_PATH) == MYMSG_FILE_EXIST)
    {
        printGreen("- DB was found = 'OK'\n");
        return MYMSG_FOUND_DB;
    }

    printRed("- DB wasn't found = 'FALSE'\n");

    if (inputAsk("create \'account.db\' file? ") != MYMSG_TRUE)
    {
        printRed("- error with creating the DB = 'FALSE'\n");
        endProgram(0);
    }

    if (createFile(DB_FILE_PATH) != MYMSG_FILE_CREATED)
    {
        printRed("- error with creating the DB file = 'FALSE'\n");
        endProgram(0);
    }

    printGreen("- created the DB = 'OK'\n");

    if (createTableAccountInDB(DB_FILE_PATH) != MYMSG_DB_SUCCESS)
    {
        printGreen("- error with creating the DB table = 'FALSE'\n");
        return MYMSG_DB_ERROR;
    }

    printGreen("- created the DB table = 'OK'\n");
    return MYMSG_SUCCESS;
}
