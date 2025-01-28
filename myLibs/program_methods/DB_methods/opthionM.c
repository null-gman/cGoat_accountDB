#include "../../../includeMyLibs.h"



void createBackup(const char *mainPathDBfile,const char *mainPathDBfileBACKUP)
{
    if(inputAsk("create a backup with curren data ?") == MYMSG_FASLE){
        return MYMSG_FASLE;
    }

    if(copyFile(mainPathDBfile,mainPathDBfileBACKUP) != MYMSG_SUCCESS)
    {
        return MYMSG_ERROR;
    }


    printGreen("\n: \'BACKUP_ACCOUNTS.db\' was created at the same dir\n\n");
    return MYMSG_SUCCESS;

}


void setBackup(const char *mainPathDBfile,const char *mainPathDBfileBACKUP)
{
     if(inputAsk("set a backup ?") == MYMSG_FASLE){
        return MYMSG_FASLE;
    }

    if(copyFile(mainPathDBfileBACKUP,mainPathDBfile) != MYMSG_SUCCESS)
    {
        return MYMSG_ERROR;
    }


    printGreen("\n: backed up\n\n");
    return MYMSG_SUCCESS;
}

void printDir(const char *mainPathDBfile)
{
    printBlue("\n: ");
    printBlue(mainPathDBfile);
    printBlue("\n\n");
}

void opthionM(const char *mainPathDBfile ,const char *mainPathDBfileBACKUP)
{

    char value[MIN_SIZE_INPUT_STRING];
    while (1)
    {
        if (inputStr("\tget dir : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            printDir(mainPathDBfile);
            continue;
        }

        //  if (inputStr("\tset dir : ", value, MIN_SIZE_INPUT_STRING)  == MYMSG_FULL_STRING)
        // {
        //     if (strCom(value, ".exit") == 1)
        //     {
        //         break;
        //     }
        //     printGray("comming soon\n");
        //     continue;
        // }

        if (inputStr("\tcreate backup : ", value, MIN_SIZE_INPUT_STRING)  == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            createBackup(mainPathDBfile,mainPathDBfileBACKUP);
            continue;
        }
           if (inputStr("\tset backup : ", value, MIN_SIZE_INPUT_STRING)  == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            setBackup(mainPathDBfile,mainPathDBfileBACKUP);
            continue;
        }
    }
}
