void endProgram(int status); //just tell you to press enter  to exit
// : pass 0 for EXIT_FAILURE  and 1 for EXIT_SUCCESS



int getProgramPathFromReg(char * dest , int buff); // open "SOFTWARE\onull_accountDB"  , key = 'DB_PATH'
//to get the dataBase PATH with db file name




int ConcatDir(const char *dir, const char *file, char * dest, size_t buffer);
