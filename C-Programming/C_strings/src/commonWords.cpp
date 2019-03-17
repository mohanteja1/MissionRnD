/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include<stdio.h>
#include <malloc.h>

#define SIZE 31
//strnlen
int findlen(char *s)
{
	int n = 0;
	while (s[n]) {
		n++;
	}
	return n;
}
//strcmp
int compareStrings(char *str1, char *str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) return 0;
		str1++;
		str2++;
	}
	if (*str1 || *str2) return 0;
	return 1;
}
//strcpy
char* stringcopy(char *destin, char *source)
{
	int i = 0;
	while (source[i])
	{
		destin[i] = source[i];
	
		i++;
	}
	destin[i] = 0;
	return destin;
}



char ** commonWords(char *str1, char *str2) {

	if (str1 == NULL || str2 == NULL)
		return NULL;


	int i = 0, j = 0,r,c;
	char *temp1[SIZE], *temp2[SIZE], tempor[SIZE], tempor2[SIZE];

   //bookmarking words in two strings
	int len1, len2,flag=1;
	len1 = findlen(str1);
	//str1
	
	stringcopy(tempor, str1);
	temp1[0] = &tempor[0];
	int loc[SIZE];

	while (i <= len1)
	{
		if (tempor[i] != 32 && i<len1)  //strings with spaces
			flag = 0;

		if (tempor[i] == 32 || tempor[i] == 0)
		{

			
		
			j++;
		
		                                 
			temp1[j] = &tempor[i + 1];
				
		                           //  \0 to space;
			tempor[i] = 0;
		
		}
		i++;


	}

	if (flag)
		return NULL;

	
	r = j;  //string 1 count of words


//string2


	len2 =findlen(str2);

	//str2
	i = 0, j = 0;
	stringcopy(tempor2, str2);

	temp2[0] = &tempor2[0];

	int loc2[SIZE];

	while (i <= len2)
	{
		if (tempor2[i] != 32 && i<len2)  //strings with spaces
			flag = 0;
	
		if (tempor2[i] == 32 || tempor2[i] == 0)
		{


			loc2[j] = i;
			j++;
		
		
			temp2[j] = &tempor2[i + 1];

			tempor2[i] = 0;
	
		}
		i++;


	}
	if (flag)
	  return NULL;
	
	c = j; //string2 count of words


	//comparisoin of words


	int t[30] = { 0 }, row = 0;
	
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if (compareStrings(temp1[i], temp2[j]))
			{
				t[row] = i;
				row++;
				 
				printf("%s\n", temp1[i]);
			}


	if (row < 1)     //if no common words found
		return NULL;


//output conversion
	char **common = (char **)malloc(row);
	for (int i = 0; i < row; i++)
	{
	
		common[i] = (char *)malloc(sizeof(char)*findlen(temp1[t[i]]));
		stringcopy(common[i], temp1[t[i]]);
	}
	
	

 
	return common;

                                        //######mohanteja####
}