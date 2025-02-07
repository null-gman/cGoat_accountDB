
#include "../../includeMyLibs.h"

void endProgram(int status)
{
  printf("\npress enter to end this program ... ");
  getchar();
  status == 1 ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}

int getProgramPathFromReg(char *dest, int buff)
{
  char value[buff];

  // char regPathStr[]  = "SOFTWARE\\onull_accountDB";
  char regPathStr[] = "SOFTWARE\\onull_test";
  // char regKeyStr[] = "DB_PATH";
  char regKeyStr[] = "testStr";
  int status = getRegValue(regPathStr, regKeyStr, value, buff);

  if (status == MYMSG_REG_ERROR)
  {

    return MYMSG_ERROR;
  }
  mystrCopy(value, dest, buff);

  return MYMSG_SUCCESS;
}

int ConcatDir(const char *dir, const char *file, char *dest, size_t buffer)
{

  size_t dirLen = strlen(dir);
  size_t filelen = strlen(dir);

  if (isDirctory(dir) == MYMSG_FASLE)
  {
    return MYMSG_ERROR;
  }

  if (filelen + dirLen > buffer)
  {
    return MYMSG_ERROR;
  }

  if ('\\' == dir[dirLen - 1])
  {
    stringConcat(dir, file, dest, buffer);
    stringConcat(dest, "\0", dest, buffer);
  }
  else
  {
    stringConcat(dir, "\\", dest, buffer);
    stringConcat(dest, file, dest, buffer);
    stringConcat(dest, "\0", dest, buffer);
  }

  return MYMSG_SUCCESS;
}
