/*

Use MainStrings1 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of Strings-1 Lesson:

->Basics of Strings / Char Arrays .
->Learn about 2D Strings
->Convert Numbers/Floats into Strings
->Manipulating Strings

*/
#include <stdio.h>
#include "FunctionHeadersStrings1.h"

int main(){

	//Test KthIndexFromEnd 

	//TestNumbertoStr

	//char str[20];
	//number_to_str(-4435.0567,str,3);

	//removeSpaces

	//char str[] = "12 w 2e     we  2 3     ";
	//removeSpaces(str);
	//printf("%s\n", str);
	
	//StrWordsinRev

	//char input[100] = "missionrnd   is   great";
	//str_words_in_rev(input,25);
	
	//commonWords
	

	char *str1 = "what do want who    ";
	char *str2 = " who what";
	char **res = commonWords(str1, str2);
	printf("%s\n", res[0]);
	printf("%s\n", res[1]);
	return 0;
}