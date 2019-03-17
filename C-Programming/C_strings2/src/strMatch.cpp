/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
int findlen2(char *s)
{
	int n = 0;
	while (s[n]) {
		n++;
	}
	return n;
}


int isSTRMatched(char *str1, char *str2){

	if (str1 == NULL && str2 == NULL)  //if both are null
		return 1;


	int str1Count = 0, str2Count = 0,i=0,j=0,tempNum=0,tempNum2=0;

	int flag1 = 0,flag2=0;

	while (str1!=0 && i<findlen2(str1))
	{
		
		while (str1[i] >= 48 && str1[i] <= 57)//if number
		{ 
			                                                    //get in between number
			tempNum = (tempNum * 10) + (str1[i] - 48);
			flag1 = 1;
			i++;

		}
		if (flag1)
		{
			str1Count += tempNum;
			flag1 = 0;   
			tempNum = 0;
			continue;
		}



		if (str1[i] >= 97 && str1[i] <= 122)//if char a-z
		{
			str1Count++;             //increament count 
			tempNum2 = 0;
			

			while ( str2Count<str1Count&&j<findlen2(str2))        //check str match till both counts are same 
			{
			
				while (str2[j] >= 48 && str2[j] <= 57)//num
				{ 
		
				tempNum2 = (tempNum2 * 10) + (str2[j] - 48);
				j++;
				flag2 = 1;
				}


				if (flag2)
				{
					str2Count += tempNum2;
					flag2 = 0;
					tempNum = 0;
					continue;
				}

				if (str2[j] >= 97 && str2[j] <= 122)//char
				{
					str2Count=str2Count+1;
					tempNum2 = 0;
				}
				
		     	j++;
			}
			
			//if strcounts match check both current alphabet chars are same
			if (str1Count == str2Count && (str2[j - 1] >= 97 && str2[j - 1] <= 122) && (str1[i] >= 97 && str1[i] <= 122))
				if (str2[j-1] != str1[i])
					  return 0;
			i++;
		}

	}


	//calculate str2 remanents ex : str1=abc38 and str 2=abc2de34  remanents are 2de34
	
	tempNum2 = 0;

	while (str2[j] && j<findlen2(str2))
	{

		while (str2[j] >= 48 && str2[j] <= 57)//num
		{   

			tempNum2 = (tempNum2 * 10) + (str2[j] - 48);
			j++;
			flag2 = 1;


		}

		if (flag2)
		{

			str2Count += tempNum2;
			flag2 = 0;
			tempNum = 0;
			continue;

		}

		if (str2[j] >= 97 && str2[j] <=122)//char
		{
			str2Count = str2Count + 1;
			tempNum2 = 0;
		
		}

		j++;

	}


	if (str1Count != str2Count)  
		return 0;


	
	return 1;
}
