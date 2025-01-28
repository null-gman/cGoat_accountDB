#include "../../../includeMyLibs.h"

// UPDATE table_name SET column1 = value1, column2 = value2...., columnN = valueN WHERE [condition];
void setSqlCommandUpdate(RECORD *record, char *dest, const char *ID)
{

  int coma = 0;
  stringConcat(dest, "UPDATE account SET ", dest, RECORD_SIZE_SQL);

  if (strlen(record->userName) > 0)
  {
    coma = 1;
    stringConcat(dest, " userName = \'", dest, RECORD_SIZE_SQL);
    stringConcat(dest, record->userName, dest, RECORD_SIZE_SQL);
    stringConcat(dest, "\' ", dest, RECORD_SIZE_SQL);
  }

  if (strlen(record->email) > 0)
  {
    if (coma == 1)
    {
      stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
    }

    stringConcat(dest, " email = \'", dest, RECORD_SIZE_SQL);
    stringConcat(dest, record->email, dest, RECORD_SIZE_SQL);
    stringConcat(dest, "\' ", dest, RECORD_SIZE_SQL);
    coma = 1;
  }

  if (strlen(record->domain) > 0)
  {

    if (coma == 1)
    {
      stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
    }
    stringConcat(dest, " domain = \'", dest, RECORD_SIZE_SQL);
    stringConcat(dest, record->domain, dest, RECORD_SIZE_SQL);
    stringConcat(dest, "\' ", dest, RECORD_SIZE_SQL);
    coma = 1;
  }

  if (strlen(record->category) > 0)
  {
    if (coma == 1)
    {
      stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
    }
    stringConcat(dest, " category = \'", dest, RECORD_SIZE_SQL);
    stringConcat(dest, record->category, dest, RECORD_SIZE_SQL);
    stringConcat(dest, "\' ", dest, RECORD_SIZE_SQL);
    coma = 1;
  }

  if (strlen(record->password) > 0)
  {
    if (coma == 1)
    {
      stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
    }
    stringConcat(dest, " password = \'", dest, RECORD_SIZE_SQL);
    stringConcat(dest, record->password, dest, RECORD_SIZE_SQL);
    stringConcat(dest, "\' ", dest, RECORD_SIZE_SQL);
    coma = 1;
  }

  if (strlen(record->note) > 0)
  {
    if (coma == 1)
    {
      stringConcat(dest, ",", dest, RECORD_SIZE_SQL);
    }
    stringConcat(dest, " note = \'", dest, RECORD_SIZE_SQL);
    stringConcat(dest, record->note, dest, RECORD_SIZE_SQL);
    stringConcat(dest, "\' ", dest, RECORD_SIZE_SQL);
    coma = 1;
  }

  // WHERE [condition];
  stringConcat(dest, " WHERE ID = ", dest, RECORD_SIZE_SQL);
  stringConcat(dest, ID, dest, RECORD_SIZE_SQL);
  stringConcat(dest, " ;", dest, RECORD_SIZE_SQL);
}



int updateRec(const char *mainPathDBfile, const char *ID)
{
  RECORD record;
  char sqlCommand[RECORD_SIZE_SQL] = {0};

  if (getRecordOp(&record) == 0)
  {
    printYellow("exits the method and not updated the account\n");
    return MYMSG_EXIT;
  }

  setSqlCommandUpdate(&record, sqlCommand, ID);


  printf("%s\n",sqlCommand);
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

  printGreen(">> account updated successfully: ");
  printGreen(ID);
  printGreen("\n");

  sqlite3_close(db);
  return MYMSG_DB_SUCCESS;
}
