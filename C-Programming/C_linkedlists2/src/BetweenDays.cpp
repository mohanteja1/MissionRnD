/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int countleapdays(int year,int monthflag)
{
	if (monthflag)        
		year--;

	return year / 4 - year / 100 + year / 400;
}


int between_days(struct node *date1head, struct node *date2head){
	//NULL check
	if (date1head == NULL || date2head == NULL)
		return -1;


	struct node *list1Current=date1head,*list2Current=date2head;

	int count = 1,temp1=0,temp2=0,leap1=0,leap2=0;

	double sum1=0, sum2=0;

	int monthCount[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	int dayConsecutiveFlag = 0, monthEqualFlag = 0, yearEqualFlag = 0;

	int month1leap = 0, month2leap = 0;

	while (list1Current!=NULL)
	{
		 
	
		temp1 = temp1*10 + list1Current->data;
		temp2 = temp2 * 10 + list2Current->data;
		
		if (count == 2)//day
		{
			sum1 += temp1 ;
			sum2 += temp2 ;


			if (temp1 == temp2 || abs(temp2 - temp1) == 1)
				  dayConsecutiveFlag = 1;

			temp1 = 0;
			temp2 = 0;
		}
		else if (count == 4)//month
		{
			sum1 += monthCount[temp1 - 1];
			sum2 += monthCount[temp2 - 1];
			
			if (temp1 == temp2)
				monthEqualFlag = 1;
			
			if (temp1 <= 2)
				month1leap = 1;
			if (temp2 <= 2)
				month2leap = 1;
			



			temp1 = 0;
			temp2 = 0;
		}
		else if (count == 8)//year
		{
			
			
			sum1 += (temp1 * 365) + countleapdays(temp1, month1leap);
			sum2 += (temp2 * 365) + countleapdays(temp2, month2leap);

			if (temp1 == temp2)
				yearEqualFlag = 1;

			temp1 = 0;
			temp2 = 0;
		}
         
		count++;
      
		//increament
		list2Current = list2Current->next;
		list1Current = list1Current->next;
	}

	printf("%d\n", yearEqualFlag);
	printf("%d\n", monthEqualFlag);
	printf("%d\n", dayConsecutiveFlag);
	if (dayConsecutiveFlag&&monthEqualFlag&&yearEqualFlag)//if same or consecutive
		return 0;

	



	return (abs(sum2 - sum1))-1;
}