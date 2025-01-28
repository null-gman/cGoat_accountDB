#include "../../includeMyLibs.h"
// #include "./sqlFuns/isIDexist.c"
#include "./DB_methods/opthionM.c"
#include "./DB_methods/selectM.c"
#include "./sqlFuns/insertRec.c"
#include "./sqlFuns/updateRec.c"
#include "./sqlFuns/deleteRec.c"








void startMethods(const char *mainDir)
{
    printf("\n");
    printCyan("choose method (type somthin and press enter to choose | type '.exit' to exit the method)\n");
    printCyan("-------------\n");


    const char dbFilePath[99] = {0} ;
    ConcatDir(mainDir,"account.db",dbFilePath,99);

    const char dbFilePath_BACKUP[99] = {0} ;
    ConcatDir(mainDir,"BACKUP_ACCOUNTDB.db",dbFilePath_BACKUP,99);


    char value[MIN_SIZE_INPUT_STRING];
    while (1)
    {
        if (inputStr("read : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            selectM(dbFilePath);
            continue;
        }

        if (inputStr("add account : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            insertRecord(dbFilePath);
            continue;
        }

        if (inputStr("opthions : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            opthionM(dbFilePath,dbFilePath_BACKUP);
            continue;
        }

        if (inputStr("update account : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            char idNum[9] = {0};
            inputStrNum("\ttype id : ", idNum, 9);
            updateRec(dbFilePath,idNum);

            continue;
        }


        if (inputStr("delete account : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            char idNum[9] = {0};
            inputStrNum("\ttype id : ", idNum, 9);
            deleteRec(dbFilePath,idNum);
            continue;
        }
    }
}
