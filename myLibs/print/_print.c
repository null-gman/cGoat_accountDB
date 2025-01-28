#include "../../includeMyLibs.h"


 //for cmd to enable ANSI colot
void enableANSI_Colors()
{
    //don't ask me how it works , ask chat GPT !
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
}


void printGreen(const char *msg)
{
    printf("\x1b[32m%s\x1b[0m", msg);
}


void printRed(const char *msg)
{
    printf("\x1b[31m%s\x1b[0m", msg);
}

void printYellow(const char *msg)
{
    printf("\x1b[33m%s\x1b[0m", msg);
}


void printBlue(const char *msg)
{
    printf("\x1b[34m%s\x1b[0m", msg);
}


void printMagenta(const char *msg)
{
    printf("\x1b[35m%s\x1b[0m", msg);
}


void printCyan(const char *msg)
{
    printf("\x1b[36m%s\x1b[0m", msg);
}


void printBold(const char *msg)
{
    printf("\x1b[1m%s\x1b[0m", msg);
}


void printBoldColor(const char *msg)
{
    printf("\x1b[1;%dm%s\x1b[0m", 33, msg);
}

void printGray(const char *msg)
{
    printf("\x1b[90m%s\x1b[0m", msg);
}
