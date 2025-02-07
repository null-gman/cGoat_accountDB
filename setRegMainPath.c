#include "./includeMyLibs.h"

/*


*/

MYMSG setRegMainPath()
{
    enableANSI_Colors(); // for cmd to enable ANSI colot

    const char myAppRegPath[] = "SOFTWARE\\onull_accountDB"; /* will contain  the full Path and dataBase file in the computer files*/
    // const char myAppRegPath[] = "SOFTWARE\\onull_test"; 

    if (inputAsk("by runig this program will check for 'SOFTWARE\\onull_test' registry and if it not found will create it") == MYMSG_FASLE)
    {
        endProgram(1);
    }

    int createRegStatus = createRegKey(myAppRegPath);

    if (createRegStatus == MYMSG_REG_ERROR)
    {
        printRed(">> error with create/open key !!\n");
        return MYMSG_ERROR;
    }
    else if (createRegStatus == MYMSG_REG_SUCCESS)
    {
        printGreen(">> reg exist run the main program !!\n");
        return MYMSG_TRUE;
    }

    char programDirctory[99] = {0};
    printYellow(">> reg not exist and created one !!\n");
    printBold("now add program dirctory that will contain the dataBase\n");
    printYellow("dirctory must be exist (the program will not create it) and with no files as end point!!\n");

    printYellow("#examples :\n");
    printGreen("     Z:\\home\\myApp\\         : this accpted\n");
    printGreen("     Z:\\home\\myApp           : this accpted\n");
    printRed("     Z:\\home\\myApp\\app.db   : this not accpted\n");

    while (1)
    {
        inputStrReq("input the dirctory (99): ", programDirctory, 99);
        if (strCom(programDirctory, ".exit") == 1)
        {
            endProgram(1);
            
        }
        if (isDirctory(programDirctory) != MYMSG_FASLE)
        {
            break;
        }
        printGray("this is not a valid dir\n");
    }
    printGreen("this is a valid dir\n");

    char keyStr[] = "DB_PATH";
    // char keyStr[] = "testStr";
    if (setRegValue(myAppRegPath, keyStr, programDirctory, 99) == MYMSG_REG_ERROR)
    {
        printRed("error with adding key value\n");
        return MYMSG_ERROR;
    }



    printGreen("now open the accountDB.exe(main program) you ready to go !\n");
    return MYMSG_TRUE;
}
