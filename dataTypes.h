

#define MIN_SIZE_INPUT_STRING 7
#define MAX_SIZE_INPUT_STRING_FOR_RECORD 254

#define RECORD_SIZE (255 * 6)
#define RECORD_SIZE_SQL ((255 * 6) + 250)



// BATA TYPES of table account in order
typedef struct
{
  // id  AUTOINCREMENT
  char userName[MAX_SIZE_INPUT_STRING_FOR_RECORD];
  char email[MAX_SIZE_INPUT_STRING_FOR_RECORD];
  char domain[MAX_SIZE_INPUT_STRING_FOR_RECORD];
  char category[MAX_SIZE_INPUT_STRING_FOR_RECORD];
  char password[MAX_SIZE_INPUT_STRING_FOR_RECORD];
  char note[MAX_SIZE_INPUT_STRING_FOR_RECORD];

} RECORD;


// typedef struct programData
// {
//  char regPath[99];
//  char regKey[99];

//  char path[99];

//  char DB_fileName[99];
//  char BACKUP_fileName[99];

//  char tableName[99];

// } programData_t;

typedef unsigned int MYMSG;


#define MYMSG_FASLE 0
#define MYMSG_TRUE 1


#define MYMSG_ERROR 2
#define MYMSG_SUCCESS 3


#define MYMSG_DB_ERROR 4
#define MYMSG_DB_SUCCESS 5
#define MYMSG_DB_SQL_ERROR 14

#define MYMSG_INVALID_INPUT 6
#define MYMSG_VALID_INPUT 7

#define MYMSG_FOUND_DB 8
#define MYMSG_NOT_FOUND_DB 9

#define MYMSG_ERROR_PATH 10
#define MYMSG_NULL_STRING 11
#define MYMSG_FULL_STRING 12
#define MYMSG_INPUT_OVERFLOW 13

#define MYMSG_FILE_NOT_EXIST 14
#define MYMSG_FILE_EXIST 15
#define MYMSG_FILE_CREATED 16
#define MYMSG_EXIT 17

#define MYMSG_REG_NOT_FOUND 18
#define MYMSG_REG_CREATED 19
#define MYMSG_REG_ERROR 20
#define MYMSG_REG_SUCCESS 21



// #define MYMSG_DB_ID_NOT_EXIST 18
// #define MYMSG_EXIT 19
