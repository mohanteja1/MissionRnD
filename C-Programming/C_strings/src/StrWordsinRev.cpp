/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	char *temp[30];//storing char pointer to store location address uto 30 spaces
	input = _strrev(input);
	//printf("%s\n", input);
	int i=0,j=0,flag1=1;
	//int loc[20];
	temp[0] = &input[0];

while (i<=len+1) 
	{ 
		
		if (input[i] == 32||input[i]==0)
		{
			
			
				//loc[j] = i;
				j++;
				//printf("loc %d =%d\n", j-1, i);
				input[i] = 0;                              // space to \0
				temp[j] = &input[i + 1];
				if (flag1)                            //if multispace skip reversing
				temp[j - 1] = _strrev(temp[j - 1]);
				//printf("%s\n", temp[j-1]);
				input[i] = 32;                           //  \0 to space
			
			if (input[i + 1] == 32)//multi space
			{
				flag1 = 0;
			}
			else
				flag1 = 1;

		}
		i++;
		

	}

input[len] = 0;
//printf("%d\n", strlen(input));
printf("%s\n", input);

}
