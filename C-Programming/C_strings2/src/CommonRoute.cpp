/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdio.h>
int findlen6(char *s)
{
	int n = 0;
	while (s[n]) {
		n++;
	}
	return n;
}

char * find_common_route(char * hacklist, char *codelist, int *cost)
{
	if (hacklist == NULL || codelist == NULL)//invalid inputs NUll check
	{
		*cost = 0;
		return NULL;
	}
	int i = 0,j=0,k=0;
	
	int current_index = 0, current_cost = 0, minCost = 0,low_index=-1,current_length=0,maximumLength=0;

	int codelen = findlen6(codelist);
	
	
	

	while (hacklist[i])
	{
		if (hacklist[i] > 90 || hacklist[i] < 65)  //check for invalid inputs in hacklist
		{
			*cost = 0;
			return NULL;
		}
		
		//find string match for current hacklist index in the codelist
		k = i;
		for (j = 0; j < codelen; j++)
		{


			if (i == 0){//check invalid input for first iteration only in the codelist
				if (codelist[j] > 90 || codelist[j] < 65)
				{
					*cost = 0;
					return NULL;
				}
			}



			current_length = 0;
			current_cost = 0;
			k = i;
		

			//continues string match
			while (codelist[j] == hacklist[k]&&codelist[j]&&hacklist[k])
			{
				current_cost = current_cost + (codelist[j] - 64);

				current_length++;
					
				k++;
				j++;
			}

			//implementing conditions 

			if (current_length >= 1)//preventing maximum length not to be zero until strngmatch
			{
				if (current_length > maximumLength) //greater lenth of strn match
				{
					low_index = i;
					maximumLength = current_length;
					minCost = current_cost;
					

				}
				else if (current_length == maximumLength)//equal lenth 
				{
					if (current_cost < minCost)//minimum cost
					{
						low_index = i;
						maximumLength = current_length;
						minCost = current_cost;
						
					}
					else if (current_cost == minCost) //if cost equals
					{
						if (hacklist[i] < hacklist[low_index])//check first char in stringmatch patterns
						{
							low_index = i;
							maximumLength = current_length;
							minCost = current_cost;
							
						}
					}
				}
			}
		}

		i++;
		
	}


	//output string
	char *output = (char*)malloc(sizeof(char)*(maximumLength + 1));
	k = 0;
	for (int m = low_index; m < low_index+maximumLength; m++)
	{
		output[k++] = hacklist[m];
	}
	output[k]=0;
	*cost = minCost;

	
	if (*cost == 0)
	{
		return NULL;
	}
	
	return output;
}