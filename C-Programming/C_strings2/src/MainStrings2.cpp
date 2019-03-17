/*

Use Strings2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Strings-2 Lesson:

->Using malloc to create new strings
->New ways of Handling Strings

Solve CommonRoute , Concat4Strings keeping complexity in Mind , BruteForce solutions take
long time to pass ,and will eventually fail when we run on our side with Timeouts .

Make Sure The Each Individual Test cases for Large inputs dosent take more than
2Seconds. (ie Real20_CommonRoute TestCase in CommonRouteSpec)
*/

#include "FunctionHeadersStrings2.h"
#include<stdio.h>
int main(){


	//Test Consonants_Vowels
	/*char str[] = "a .?2343 BCDE mu";
	int consonants;
	int vowels;
	count_vowels_and_consonants(str, &consonants, &vowels);*/

	
	/*char str[] = "abcdefgh";

	printf("%s\n", str);
	int i = 0;
	int j = 2;
	int k;
	for (i = 0; i <= 1; i++){
		for (j = 3; j < 7; j++){
			char *new_str = get_sub_string(str, i, j);
			printf("%d--%d\n", i, j);
			printf("%s\n", new_str);
		}
	}*/
//Test getFrequencyofWord
	/*char sentences[][100] = { "abababa", "he he", "ab cd ab cd", "    ", "1234 aaaaaaa", "asd324", "yzqwer 23425", "a" };
	char words[][100] = { "ab", "he", "ab cd", " ", "aa", "asd324", "x", "a" };
	int counts[100] = { 3, 2, 2, 4, 6, 1, 0 };
	int sc = 7;
	int si = 0;
	for (si = 0; si < sc; si++){
		int temp_c = count_word_int_str_way_2_recursion(sentences[si], words[si]);
		printf("%d\n", temp_c);

	}
*/

	//Test getSubstring
	/*int actualAns = isValidEmail("MAnOJ m_mAnOjabc@gmail.com");
	printf("----%d\n", actualAns);*/
	//Test getLastWord



	//Test others
	//strMatch
	/*char s1[100] = "1bc2d1";
	char s2[100] = "2c4";
	int expectedAns = 1;
	int actualAns = isSTRMatched(s1, s2);
	printf("%d\n", actualAns);*/
	
	/*
	testSimpleCaseP1("1bc2d1", "2c4", 1);
	testSimpleCaseP1("1bc4", "ebcabcd", 1);
	testSimpleCaseP1("abc3", "e", 0);
*/
	
	
	//int operation = 4;
	//char str1[100] = "1011101110111111111111000000";
	//char str2[100] = "1010111101010001010111101010111111111100000010101011101100010101";
	//char eans[100] = "0101000010101110101000010101000000000000010001000000000000101010";

	////printf("%d\n", strlen(str1));
	//char open[5] = "NOR";
	//char * ans = performOperation(str1, str2,open);
	//printf("%s\n", ans);

	int cost = -1;
	char hacklist[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char codelist[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ans[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	char *res = NULL;
	res = find_common_route(hacklist, codelist, &cost);
	printf("%s\n", res);
	printf("%d\n", cost);

	return 0;
}