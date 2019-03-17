/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char removeSpaces(char *str) {

	//error cases
	
	if (str == 0)
		return '\0';
		
	int i=0;

	char *readptr, *writeptr;
	readptr = str;
	writeptr = str;

	while (*readptr != 0)
	{

		//if space encountered
			while (*readptr==32)//move read pointer to nonspace char
			readptr++;

			if (*readptr == 0)
				break;

		*writeptr = *readptr;//move char from readptr to write ptr
		
		i++;
		writeptr++;
		readptr++;

	}
	
	str[i] = 0;

	return *str;
}