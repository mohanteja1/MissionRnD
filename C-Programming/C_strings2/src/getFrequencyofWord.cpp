/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
int findlen(char *s)
{
	int n = 0;
	while (s[n]) {
		n++;
	}
	return n;
}
int count_word_in_str_way_1(char *str, char *word){
	if (str == NULL || word == NULL)
		return 0;


	int count = 0,jcount=0,temp;
	int i = 0, j = 0;
	int word_len = findlen(word);
	while (str[i])
	{
		jcount = 0;
		temp = i;
		while (str[i] == word[jcount] && word[jcount])
		{
			jcount++;
			i++;
		}
		i = temp ;
		if (jcount == word_len)
			count++;
		i++;
	}

	return count;
}

int countrecursivefun(char *str,char *word,int word_len)
{
	if (str[0] == 0)
		return 0;

	int i = 0,jcount=0,count=0;
	int temp;
	temp = i;
		while (str[i] == word[jcount] && word[jcount]&&str[i])
		{
			jcount++;
			i++;
		}
		i = temp + 1;
		if (jcount == word_len)
			count++;
		
		return count + countrecursivefun(&str[i], word, word_len);

}


int count_word_int_str_way_2_recursion(char *str, char *word){

	if (str == NULL || word == NULL)
		return 0;
	int count = countrecursivefun(str, word, findlen(word));

	return count;
}

