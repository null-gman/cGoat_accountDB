int createRegKey(const char *path);

int getRegValue(char *path, char *key, char *dest, DWORD destBuffer);

int setRegValue(char *path, char *key, char *value, DWORD valueSize);
