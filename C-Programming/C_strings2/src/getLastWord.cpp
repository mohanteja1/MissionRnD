/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL)
		return NULL;
	int i = 0,lastwIndex=0,n=0;
	
	while (str[i])
	{
		if (str[i] == 32)
			lastwIndex = i+1;
		i++;
	}
	char *lastword = (char*)malloc((i - lastwIndex)*sizeof(char));

	for (int k = lastwIndex; k <= i; k++)
		lastword[n] = str[k];


	return lastword;
}
