#include "../../../includeMyLibs.h"

//"INSERT INTO accounts ""(userName,email,domain "category,password,note)VALUES('",)))))

void setSqlCommandInsert(RECORD *record, char *dest)
{
  stringConcat("INSERT INTO account "
               "(userName,email,domain,"
               "category,password,note)VALUES('",
               record->userName ? record->userName : "~NULL", dest, RECORD_SIZE_SQL);
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
  // user

  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, record->email ? record->email : "~NULL", dest, RECORD_SIZE_SQL);
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
  // email
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, record->domain ? record->domain : "~NULL", dest, RECORD_SIZE_SQL);
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
  // domain
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, record->category ? record->category : "~NULL", dest, RECORD_SIZE_SQL);
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
  // category
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, record->password ? record->password : "~NULL",
               dest, RECORD_SIZE_SQL);
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
  // password
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  stringConcat(dest, record->note ? record->note : "~NULL",
               dest, RECORD_SIZE_SQL);
  stringConcat(dest, "'", dest, RECORD_SIZE_SQL);
  // note

  stringConcat(dest, ");", dest, RECORD_SIZE_SQL);
}

int insertRecord(const char *mainPathDBfile)
{
  RECORD record;
  char sqlCommand[RECORD_SIZE_SQL] = {0};

  if(getRecord(&record) == 0){
    printYellow("exits the method and not added the account\n");
    return MYMSG_EXIT;
  }

  setSqlCommandInsert(&record, sqlCommand);

  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  rc = sqlite3_open(mainPathDBfile, &db);
  // printYellow(sqlCommand);
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

  printGreen(">> account added successfully\n");
  sqlite3_close(db);
  return MYMSG_DB_SUCCESS;
}
