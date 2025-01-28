#include "../../../includeMyLibs.h"
#include "../sqlFuns/selectAll.c"

#include "../sqlFuns/selectID.c"
#include "../sqlFuns/selectCat.c"
#include "../sqlFuns/selectDomain.c"


void selectM(const char *mainPathDBfile)
{

    char value[MIN_SIZE_INPUT_STRING];
    while (1)
    {
        if (inputStr("\tread all : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }
            selectALL(mainPathDBfile);
            continue;
        }
        if (inputStr("\tread by ID : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }

            char numId[9] = {0};
            inputStrNum("\t\ttype id : ", numId, 9);
            selectID(mainPathDBfile, numId);
            continue;
        }

        if (inputStr("\tread by category : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }

            char category[MAX_SIZE_INPUT_STRING_FOR_RECORD] = {0};
            inputStrReq("\t\ttype category : ", category, MAX_SIZE_INPUT_STRING_FOR_RECORD);
            selectCat(mainPathDBfile, category);
            continue;
        }


        if (inputStr("\tread by domain : ", value, MIN_SIZE_INPUT_STRING) == MYMSG_FULL_STRING)
        {
            if (strCom(value, ".exit") == 1)
            {
                break;
            }

            char domain[MAX_SIZE_INPUT_STRING_FOR_RECORD] = {0};
            inputStrReq("\t\ttype domain : ", domain, MAX_SIZE_INPUT_STRING_FOR_RECORD);
            selectDomain(mainPathDBfile, domain);
            continue;
        }
    }
}
