/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/
#include "FunctionHeadersArrays1.h"
#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {

	//errorcases
	if (students == NULL || len<0 || K <= 0)
		return NULL;

	for (int n = 0; n < len; n++)
	{
		//top[n] = &students[flag[n]];
		printf("%d\n", students[n].score);
	}
	printf("-----------\n");

	

	int i = 0, j = 0, n,least=0,temp = 0, *arr;
	//flag index integer array
	
	int *flag = (int*)malloc(sizeof(int)*len);
	for (n = 0; n < len; n++)
		flag[n] = 0;


	//actual logic
	int len1 = len;

  while (len--)
	{
		//fill flag index array 
		if (i < K)
		{
			flag[i] = i;
		}
		else
		{
			//select the least index
			for (j = 0; j < K; j++)
				if (students[flag[j]].score <students[flag[least]].score)
					least = j;

			//replacing least
			if (students[i].score > students[flag[least]].score)
				flag[least] = i;
		}
		i++;

	}
	//conversion of output from index to given data type
	struct student **top = (student**)malloc(K*sizeof(student));
	for (n = 0; n < K &&n <len1; n++)
	{
		top[n] = &students[flag[n]];
	}

	return top;

	

}