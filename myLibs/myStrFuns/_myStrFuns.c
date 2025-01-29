
#include "../../includeMyLibs.h"


/*
take a pointer to string and remove all white spaces after last Character in string and
remover all white spaces before first Character
*/
int trimStr(char *string)
{
	size_t stringLen = strlen(string); // get the number of chars of the string
	char newString[stringLen + 1] ; // will contain the trimed string

	if (stringLen == 0)
	{
		string[0] = '\0';
		return 1; //blank string
	}

	size_t indexForNewString = 0;
	size_t isAllCharsWhiteSpaces = 0;
	for (size_t i = 0; i < stringLen; i++)
	{
		if (string[i] != ' ' && string[i] != '\0')
		{
			isAllCharsWhiteSpaces = 1;
		}
	}

	if (isAllCharsWhiteSpaces == 0)
	{
		string[0] = '\0';
		return 1; //all string is white spaces
	}

	size_t fisrtCharAtString = 0;  // fist char index that not white space at the string
	size_t lastCharAtString = 0;	// last char index that not white space at the string

	// get the first char index that not a white space
	for (size_t i = 0; i < stringLen + 1; i++)
	{
		if (string[i] != ' ')
		{
			fisrtCharAtString = i;
			break;
		}
	}

	// get the last char index that not a white space
	for (size_t i = stringLen - 1; i > 0; i--)
	{
		if (string[i] != ' ')
		{
			lastCharAtString = i;
			break;
		}
	}

	// get all char bettewn the fisrt and last in newString to copy it later
	for (size_t i = fisrtCharAtString; i < lastCharAtString + 1; i++)
	{
		newString[indexForNewString] = string[i];
		indexForNewString++;
	}
	newString[indexForNewString] = '\0'; // to end it

	// 	copy newString into string
	for (size_t i = 0; i < indexForNewString + 1; i++)
	{
		string[i] = newString[i];
	}

	return 1;
}


/*
 * compaer two string return 1 if TRUE and 0 if FASLE
 */
int strCom(char *str1, char *str2)
{
	size_t str1Len = strlen(str1);
	size_t str2Len = strlen(str2);


	//prevent overflow
	if (str1Len != str2Len)
	{
		goto notEqual;
	}

	int res = strcmp(str1, str2);

	if (res == 0)
	{
		return 1; // Equal
	}

notEqual:
	return 0;
}

int stringConcat(const char *str1, const char *str2, char *dest, const int buffSize)
{
	size_t str1Size = strlen(str1);
	size_t str2Size = strlen(str2);


	//prevent overflow
	if (str1Size + str2Size + 1 > buffSize)
	{
		return 0;
	}

	size_t indexDest = 0;

	for (size_t i = 0; i < str1Size; i++)
	{
		dest[indexDest] = str1[i];
		indexDest++;
	}

	for (size_t i = 0; i < str2Size; i++)
	{
		dest[indexDest] = str2[i];
		indexDest++;
	}

	dest[indexDest] = '\0';
	return 1;
}


/*
	replace " and ' to _ to prevent sql injection
*/
void strInputFormat(char *str)
{
	size_t strLen = strlen(str);

	for (size_t i = 0; i < strLen; i++)
	{
		if (str[i] == '"' || str[i] == '\'' || str[i] == '`')
		{
			str[i] = '_';
		}
	}
}


/*
	rsafer strcopy function
*/
int mystrCopy(const char *sourc, char *dest, int buff)
{

	//prevern over flow
	for (size_t i = 0; i < buff; i++)
	{
		if (sourc[i] == '\n' || sourc[i] == '\0' || sourc[i] == EOF)
		{
			dest[i] = '\0';
			break;
		}

		dest[i] = sourc[i];
	}

	dest[buff - 1] = '\0';

	return MYMSG_SUCCESS;
}




//not used
// short charToNum(char c)
// {

// 	switch (c)
// 	{
// 	case '0':
// 		return 0;
// 	case '1':
// 		return 1;
// 	case '2':
// 		return 2;
// 	case '3':
// 		return 3;
// 	case '4':
// 		return 4;
// 	case '5':
// 		return 5;
// 	case '6':
// 		return 6;
// 	case '7':
// 		return 7;
// 	case '8':
// 		return 8;
// 	case '9':
// 		return 9;
// 	}

// 	return -1;
// }

// unsigned int power(int num, int rep)
// {
// 	unsigned int res = 1;
// 	for (unsigned int i = 0; i < rep; i++)
// 	{
// 		res *= num;
// 	}
// 	return res;
// }

// unsigned int strToNum(char *str)
// {

// 	unsigned int res = 0;
// 	unsigned int zerosIn = strlen(str) - 1;
// 	unsigned int index = zerosIn;

// 	//"123"

// 	for (unsigned int i = 0; i < zerosIn + 1; i++)
// 	{
// 		res += charToNum(str[i]) * power(10, index);
// 		index--;
// 	}

// 	return res;
// }
