/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdlib.h>
int findlen4(char *s)
{
	int n = 0;
	while (s[n]) {
		n++;
	}
	return n;
}

char *AND(char *str1, char *str2)
{
	int i,len = findlen4(str1);
	char *output = (char*)malloc(sizeof(char)*len+1);
	for (i = 0; i < len; i++)
	{
		output[i] = (str1[i] == '0' || str2[i] == '0') ? 48 : 49;
	}
	output[i] = 0;
	return output;
}

char *OR(char *str1, char *str2)
{
	int i,len = findlen4(str1);
	char *output = (char*)malloc(sizeof(char)*len+1);
	for ( i = 0; i < len; i++)
	{
		output[i] = (str1[i] == '1' || str2[i] == '1' ) ? 49 : 48;
	}
	output[i] = 0;
	return output;
}
char *NOR(char *str1, char *str2)
{
	int i,len = findlen4(str1);
	char *output = (char*)malloc(sizeof(char)*len+1);
	for ( i = 0; i < len; i++)
	{
		output[i] = (str1[i] == '1' || str2[i] == '1') ? 48 : 49;
	}
	output[i] = 0;
	return output;
}
char *XOR(char *str1, char *str2)
{
	int i, len = findlen4(str1);
	char *output = (char*)malloc(sizeof(char)*len+1);
	for ( i = 0; i < len; i++)
	{
		output[i] = (str1[i] ==  str2[i] ) ? 48 : 49;
	}
	output[i] = 0;
	return output;
}
char *performOperation(char *str1, char *str2, char *operation)
{
	/*if (str1 == NULL || str1 == NULL || operation == NULL)   //NUllcheck
		return NULL;*/
	int str1length = findlen4(str1);
	int str2length = findlen4(str2);
	
	int len = findlen4(str1);
	

	int j = 0;
    int i = 0;
	/*if (str1length >= 50 || str2length >= 50)  //given constraint
		return NULL;*/

	//char *output;
	char *str1copy, *str2copy;  //duplicate pointers

	if (str1length > str2length)
	{
		str2copy = (char *)malloc(sizeof(char)*str1length+1);

		for (i = 0; i < str1length; i++)
		{
			if (i < str1length-str2length)
				str2copy[i] = '0';
			else
				str2copy[i] = str2[j++];

		}
		str2copy[i] = 0;
		str1copy = str1;
	 }
	else if (str1length < str2length)
	{
		str1copy = (char *)malloc(sizeof(char)*str2length+1);
		

		for (i = 0; i < str2length; i++)
		{
			if (i < str2length - str1length)
				str1copy[i] = '0';
			else
				str1copy[i] = str1[j++];
	
		}
		str1copy[i] = 0;
		str2copy = str2;
	}
	else          //if string lenths equal
	{
		
		str1copy = str1;
		str2copy = str2;
	}






	switch ( operation[0] )
	{
	case  'A':
		return AND(str1copy, str2copy);
		break;
	case  'N':
		return NOR(str1copy, str2copy);
		break;
	case  'O':
		return OR(str1copy, str2copy);
		break;
	case  'X':
		return XOR(str1copy, str2copy);
		break;

	}
	return NULL;

}








