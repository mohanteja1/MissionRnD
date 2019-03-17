/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with many doors with each door having a passkey.
A Pass key is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors are 3, 1223,2132,2321 can be passkeys for those doors. 
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 2nd door.

Lets say the final pass key she has is 758.
First door pass key is the largest number that can be formed by given final passkey -> 875
Second door pass key is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 : 
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways. 
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};

int factorial(int num)
{
	if (num <= 1)
		return 1;
	else 
		return num*factorial(num - 1);
}

int position(int *hashtable, int digit)
{
	int i = 9,pos=0,noofdigitsRem=0;
	
	if (hashtable[digit] > 0)
		hashtable[digit]--;

	while (i>=0)
	{
		if (i >= digit)
		{
			if (hashtable[i] != 0)
				pos += hashtable[i];
				
		}
		
		i--;
	}
	

	return pos;
}









int doorstoCross(struct passKeyNode *passKeyHead)
{
	if (passKeyHead == NULL)
		return -1;

	int *hashCount = (int*)calloc(10, sizeof(int));//for ten digits 0 to 9 incase of duplicates and digit presense 
	
	struct passKeyNode *listCurrent = passKeyHead, *tempNode;
	int count = 0, passKeyCount = 0;
	
	int duplicateFlag = 0;
	while (listCurrent != NULL)
	{
		count++;
		hashCount[listCurrent->num]++;  //count digit occurence

		if (hashCount[listCurrent->num] > 1) //check duplicates
			duplicateFlag = 1;
		listCurrent = listCurrent->next;
	}
	//point it to head again
	listCurrent = passKeyHead;
	

	

	

	if (!duplicateFlag){   //if duplicate digits not found 
		
		
		int pos = 0, fact = 0;
		while (count > 0)//less complexity
		    {
			

			pos = position(hashCount, listCurrent->num);

			fact = factorial(--count);

			passKeyCount += pos*fact;    //multiply current (highest)position of number or rank * current (count--) factorial   
		
			//move right
			listCurrent = listCurrent->next;
			
		}

	}
	else  //if duplicate digits found
		{
	//coun2 for temp storage of count
   //tempcount :to count digits less than the current digit to its right
			//tempduplicateFact for dividing the temp count with duplicatecount factorial 
			//tempdigit for temp storing of each digit calculation   //debugging 
	    int tempcount = 0,tempduplicateFact=0,flag,Count2=count,tempdigitfact;

		//loop counts rank in descending order
		while (listCurrent != NULL)
		{
			int hash[10] = { 0 };  //used to avoid counting of duplicate values again. like if more digits has duplicate  
			tempNode = listCurrent->next;
			tempduplicateFact = 1;
			tempcount = 0;
			flag = 1;

			//calcution of every digit factorial

			while (tempNode != NULL)
			{

				if (tempNode->num < listCurrent->num)  // loopnode value less than listcurrent value is counted for tempcount and tempduplicatfact  
				{
					if (hash[tempNode->num] == 0)
					{
						tempcount += hashCount[tempNode->num];
						if (hashCount[tempNode->num] > 1)
						{

							if (flag)
							{
								tempduplicateFact = 0;
								flag = 0;
							}
							tempduplicateFact += factorial(hashCount[tempNode->num]);

						}
						hash[tempNode->num] = -1;
					}
				}

				if (listCurrent->num == tempNode->num) //to avoid neglecting of duplicate count if listcurrent digit is also duplicate
				{
					if (hash[tempNode->num] == 0)
					{
						if (flag)
						{
							tempduplicateFact = 0;
							flag = 0;
						}
						tempduplicateFact += factorial(hashCount[tempNode->num]);
						hash[tempNode->num] = -1;
					}
				}



				tempNode = tempNode->next;
			}

			count--;

			tempdigitfact = ((tempcount*factorial(count)) / tempduplicateFact);

			passKeyCount += tempdigitfact; //total addition

			listCurrent = listCurrent->next;
		}



		//this loop is for total count of duplicate factorials ( d1!+d2!+d3!.......)
		
		tempduplicateFact = 0;
		for (int i = 0; i < 10; i++)
		{
			if (hashCount[i]>1)
				tempduplicateFact += factorial(hashCount[i]);
		}

		//total permutations -currentrank in ascending order=rank in descending order
		passKeyCount = (factorial(Count2)/tempduplicateFact) - passKeyCount;
		//no need of reducing 1 since count differnce starts from 1;

		return passKeyCount;
		}


		return passKeyCount + 1;
	
}