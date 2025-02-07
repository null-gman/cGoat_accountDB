#include "../../includeMyLibs.h"

int isFileExist(const char *file)
{
    FILE *pF = fopen(file, "r");

    if (pF)
    {
        fclose(pF);
        return MYMSG_FILE_EXIST;
    }

    fclose(pF);
    return MYMSG_FILE_NOT_EXIST;
}

int copyFile(const char *fileSource, const char *fileDest)
{

    if (isFileExist(fileSource) == 0)
    {

        return MYMSG_FILE_NOT_EXIST;
    }

    FILE *Source_pF = fopen(fileSource, "rb");

    if (!Source_pF)
    {
        fclose(Source_pF);

        return MYMSG_ERROR;
    }

    FILE *dest_pF = fopen(fileDest, "wb");

    if (!dest_pF)
    {
        fclose(dest_pF);
        return MYMSG_ERROR;
    }

    unsigned char BUFFER[10];

    while (fread(BUFFER, sizeof(BUFFER), 1, Source_pF))
    {
        fwrite(BUFFER, sizeof(BUFFER), 1, dest_pF);
    }

    fclose(dest_pF);
    fclose(Source_pF);

    return MYMSG_SUCCESS;
}

int createFile(const char *fileName)
{
    FILE *pF = fopen(fileName, "wb");

    if (pF)
    {
        fclose(pF);
        return MYMSG_FILE_CREATED;
    }

    fclose(pF);
    return MYMSG_ERROR;
}

int deletFile(const char *fileName)
{
    if (remove(fileName) == 0)
    {
        return MYMSG_SUCCESS;
    }
    else
    {
        return MYMSG_ERROR;
    }

    return MYMSG_ERROR;
}

int isDirctory(const char *dir)
{
    size_t dirLen = strlen(dir);
    size_t sizeForMYDir = dirLen + 20;

    char fullDirWithFile[sizeForMYDir];
    if (dir[dirLen] == '\\')
    {
        stringConcat(dir, "file.file", fullDirWithFile, sizeForMYDir);
    
    }
    else
    {
        stringConcat(dir, "\\file.file", fullDirWithFile, sizeForMYDir);
 
    }

    puts(fullDirWithFile);
    if (createFile(fullDirWithFile) == MYMSG_ERROR)
    {
        return MYMSG_FASLE;
    }

    deletFile(fullDirWithFile);
    return MYMSG_TRUE;
}
