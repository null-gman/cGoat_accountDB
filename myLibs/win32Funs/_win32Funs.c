#include "../../includeMyLibs.h"

int createRegKey(const char *path)
{

    HKEY out;
    DWORD outStatus;

    LSTATUS status = RegCreateKeyExA(HKEY_CURRENT_USER, path, 0,
                                     NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,
                                     &out, &outStatus);
    RegCloseKey(out);
    if (status != ERROR_SUCCESS)
    {

        return MYMSG_REG_ERROR;
    }

    if (outStatus == REG_CREATED_NEW_KEY)
    {

        return MYMSG_REG_CREATED;
    }
    else if (outStatus == REG_OPENED_EXISTING_KEY)
    {

        return MYMSG_REG_SUCCESS;
    }

    return MYMSG_REG_SUCCESS;
}

int getRegValue(char *path, char *key, char *dest, DWORD destBuffer)
{

    HKEY reg;
    LONG status = RegOpenCurrentUser(KEY_ALL_ACCESS, &reg);

    if (status != ERROR_SUCCESS)
    {
        RegCloseKey(reg);
        return MYMSG_REG_ERROR;
    }

    LSTATUS status2 = RegGetValueA(reg, path, key, RRF_RT_ANY, NULL, dest, &destBuffer);
    RegCloseKey(reg);

    if (status2 != ERROR_SUCCESS)
    {

        return MYMSG_REG_NOT_FOUND;
    }

    return MYMSG_REG_SUCCESS;
}

int setRegValue(char *path, char *key, char *value, DWORD valueSize)
{
    HKEY reg;
    LONG status = RegOpenCurrentUser(KEY_ALL_ACCESS, &reg);

    if (status != ERROR_SUCCESS)
    {
        RegCloseKey(reg);
        return MYMSG_REG_ERROR;
    }

    LSTATUS status2 = RegSetKeyValueA(reg, path, key, REG_SZ, value, valueSize);
    RegCloseKey(reg);

    if (status2 != ERROR_SUCCESS)
    {

        return MYMSG_REG_ERROR;
    }

    return MYMSG_REG_SUCCESS;
}
