/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>
#include<stdio.h>
int binarysearch( int num,int *vowels,int low,int high)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (vowels[mid] == num)
			return mid;
		else if (vowels[mid] < num)
		{
			low = mid + 1;
			return binarysearch(num, vowels, low, high);
		}
		else
		{
			high = mid - 1;
			return binarysearch(num, vowels, low, high);
		}
	}
	return -1;
}
void count_vowels_and_consonants(char *str, int *consonants, int *vowels)
{
	if (str == NULL)
	{
		*vowels = 0;
		*consonants = 0;
		return;
	}


	int vowel[10] = { 65, 69, 73, 79, 85, 97, 101, 105, 111, 117 };
	*vowels = 0;
	*consonants = 0;
	int k=binarysearch(69, vowel,0,9);
	int i = 0;
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			if (binarysearch(str[i], vowel, 0, 9) == -1)
				(*consonants)++;
			else
				(*vowels)++;
		
		i++;
	}
	return ;
}
