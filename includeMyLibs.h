#ifndef MAIN_MY_LIB_H
#define MAIN_MY_LIB_H



/*
 * DON'T CHANGE ORDER OF THE LIBS !!!!!!!
 * thay are dependatint
 */


#include <stdio.h>
// #include <stdlib.h>  //not used
#include <string.h>
#include <windows.h> // for geting registry and enable ANSI colors for cmd
#include "./dataTypes.h" //my msg macros and RECORD struct



#include "./myLibs/print/_Hprint.h" //colored print

#include "./myLibs/win32Funs/_Hwin32Funs.h"  // working with windows registy
#include "./myLibs/utilities/_Hutilities.h" // funs that used in program
#include "./myLibs/fsFuns/_HfsFuns.h"          // file system funs
#include "./myLibs/myStrFuns/_HmyStrFuns.h"  // my string lib the stander string is sucks
#include "./myLibs/inputFuns/_HinputFuns.h" // input funs the get RECORD values and number as string and input like python

#include "./sqlite3Lib/sqlite3.h"
#include "./myLibs/program_methods/_HDB_Funs.h" //all methodes that uses can uses


MYMSG setRegMainPath();



#endif
