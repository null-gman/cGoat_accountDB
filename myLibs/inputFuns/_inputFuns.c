#include "../../includeMyLibs.h"

void freeBuffAfterFgets()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
    //net and dust
  };
}




/*
 *
 *  all input funs will trim the string
 *
 */

int inputStr(const char *msg, char *dest, int buff)
{
  printBold(msg);

  if (fgets(dest, buff, stdin) == NULL)
  {
    // no string inputs
    return MYMSG_NULL_STRING;
  }

  size_t len = strlen(dest);

  if (len > 0 && dest[len - 1] == '\n')
  {
    dest[len - 1] = '\0';
  }
  else
  {
    freeBuffAfterFgets();
    return MYMSG_INPUT_OVERFLOW;
  }

  trimStr(dest);
  return (strlen(dest) == 0) ? MYMSG_NULL_STRING : MYMSG_FULL_STRING;
}

int inputAsk(char *msg)
{
  char answare[MIN_SIZE_INPUT_STRING];
  while (1)
  {
    printBold(msg);
    inputStr("(y/n): ", answare, MIN_SIZE_INPUT_STRING);
    trimStr(answare);
    if (strlen(answare) > 0)
    {
      break;
    }
  }

  if (tolower(answare[0]) == 'y')
  {
    return MYMSG_TRUE;
  }
  else
  {
    return MYMSG_FASLE;
  }
}

void inputStrNum(char *string, char *dest, int buff)
{
  int len = 0;
  while (1)
  {
  startWhileLoop:
    if (inputStr(string, dest, buff) == MYMSG_INPUT_OVERFLOW)
    {
      printf(">> overFlow max char = %d\n", buff - 1);
      goto startWhileLoop;
    }

    trimStr(dest);
    len = strlen(dest);
    if (len == 0)
    {
      printf("type somthing\n");
      goto startWhileLoop;
    }

    for (int i = 0; i < len; i++)
    {
      if ((int)dest[i] < 48 || (int)dest[i] > 57)
      {
        printf("not a number\n");
        goto startWhileLoop;
      }
    }

    break;
  }
}

void inputStrReq(const char *string, char *dest, int buff)
{
  while (1)
  {

    if (inputStr(string, dest, buff) == MYMSG_ERROR)
    {
      printf(">> overFlow max char = %d\n", buff - 1);
      continue;
    }

    if (strlen(dest) != 0)
    {
      break;
    }

    printf(">> type somsing\n");
  }
}

int inputStrRecord(const char *msg, char *dest)
{
  inputStrReq(msg, dest, MAX_SIZE_INPUT_STRING_FOR_RECORD);
  trimStr(dest);
  strInputFormat(dest);

  if (strCom(dest, ".exit"))
  {
    return 1;
  }

  return 0;
}

int inputStrRecordOp(const char *msg, char *dest)
{
  inputStr(msg, dest, MAX_SIZE_INPUT_STRING_FOR_RECORD);
  trimStr(dest);
  strInputFormat(dest);

  if (strCom(dest, ".exit"))
  {
    return 1;
  }

  return 0;
}


int getRecord(RECORD *dest)
{
  if (inputStrRecord("\tuser name : ", dest->userName))
  {
    return 0;
  }

  if (inputStrRecord("\temail : ", dest->email))
  {
    return 0;
  }

  if (inputStrRecord("\tdomain : ", dest->domain))
  {
    return 0;
  }

  if (inputStrRecord("\tcategory: ", dest->category))
  {
    return 0;
  }

  if (inputStrRecord("\tpassword : ", dest->password))
  {
    return 0;
  }

  if (inputStrRecord("\tnote: ", dest->note))
  {
    return 0;
  }

  return 1;
}


int getRecordOp(RECORD *dest)
{
  if (inputStrRecordOp("\tuser name : ", dest->userName))
  {
    return 0;
  }

  if (inputStrRecordOp("\temail : ", dest->email))
  {
    return 0;
  }

  if (inputStrRecordOp("\tdomain : ", dest->domain))
  {
    return 0;
  }

  if (inputStrRecordOp("\tcategory: ", dest->category))
  {
    return 0;
  }

  if (inputStrRecordOp("\tpassword : ", dest->password))
  {
    return 0;
  }

  if (inputStrRecordOp("\tnote: ", dest->note))
  {
    return 0;
  }

  return 1;
}
