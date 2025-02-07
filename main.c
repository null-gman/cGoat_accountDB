#include "./includeMyLibs.h"

/*

    An Account Management CLI Program that allows you to easily add new accounts and update them,
  using SQLite3 as the database management system (DBMS).
  The program runs anywhere via CMD or any terminal by adding it to the PATH variable on your computer.
  It also retrieves and accesses a specific database file using a Windows registry key.
  The program features a user-friendly interface for seamless account management.

*/

void main()
{
  enableANSI_Colors(); // for cmd to enable ANSI colot

  char programDir[150]; // will contain  the full Path and dataBase file in the computer files
  if (getProgramPathFromReg(programDir, 150) == MYMSG_ERROR)
  {
    printYellow(">> there is no registry Path for program ! \n");

    if (setRegMainPath() != MYMSG_TRUE)
    {
      endProgram(1);
    }
    if (getProgramPathFromReg(programDir, 150) == MYMSG_ERROR)
    {
      printYellow(">> erorr registry Path for program ! \n");
      endProgram(1);
    }
  }

  char programDirWithFileName[150];

  char DBFileName[] = "account.db";
  if (ConcatDir(programDir, DBFileName, programDirWithFileName, 150) == MYMSG_ERROR)
  {
    printRed("error with createing db path!!");
    endProgram(0);
  }

  checkDB(programDirWithFileName); // check if the file exist if not will create it and create table "account"
  startMethods(programDir);        // ask user what method want to run .
  endProgram(1);
}

/*

TODO

  put all variables in one struct (reg path , reg value , data base file name , table name , path ,
                                   backUpFile)


*/