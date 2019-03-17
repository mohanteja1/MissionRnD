/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int i=0, x, y, sum1[3] = { 0 }, sum2[3] = { 0 };

	while (*dob1 != '\0' && *dob2 != '\0')
	{
		//error cases :if both dont have separation symbool at same length
		if (*dob1 != '-' && *dob2 == '-' || *dob1 == '-' && *dob2 != '-')
			return -1;
		
		if(*dob1 != '-' && *dob2 != '-')
		{
		
			x = (int)*dob1 - 48;
			y = (int)*dob2 - 48;
			sum1[i] = sum1[i] * 10 + x;//generating 3 integers day month year for two date of births
			sum2[i] = sum2[i] * 10 + y;
		}
		if (*dob1 == '-' && *dob2 == '-')
		{
			
			i++;
		}
		*dob1++;
		*dob2++;

	}


	//check year
	if (sum1[2] >= 1900 && sum1[2] <= 9999 && (sum2[2] >= 1900 && sum2[2] <= 9999))
	{
		//check month
		if (sum1[1] >= 1 && sum1[1] <= 12 && sum2[1] >= 1 && sum2[1] <= 12)
		{
			//check days
		    //dob1
			if ((sum1[0] >= 1 && sum1[0] <= 31) && (sum1[1] == 1 || sum1[1] == 3 || sum1[1] == 5 || sum1[1] == 7 || sum1[1] == 8 || sum1[1] == 10 || sum1[1] == 12))
				;
			else if ((sum1[0] >= 1 && sum1[0] <= 30) && (sum1[1] == 4 || sum1[1] == 6 || sum1[1] == 9 || sum1[1] == 11))
				;
			else if ((sum1[0] >= 1 && sum1[0] <= 28) && (sum1[1] == 2));

			else if (sum1[0] == 29 && sum1[1] == 2 && (sum1[2] % 400 == 0 || (sum1[2] % 4 == 0 && sum1[2] % 100 != 0)));

			else
				return -1;


			//dob2
			if ((sum2[0] >= 1 && sum2[0] <= 31) && (sum2[1] == 1 || sum2[1] == 3 || sum2[1] == 5 || sum2[1] == 7 || sum2[1] == 8 || sum2[1] == 10 || sum2[1] == 12))
				;
			else if ((sum2[0] >= 1 && sum2[0] <= 30) && (sum2[1] == 4 || sum2[1] == 6 || sum2[1] == 9 || sum2[1] == 11))
				;
			else if ((sum2[0] >= 1 && sum2[0] <= 28) && (sum2[1] == 2));

			else if (sum2[0] == 29 && sum2[1] == 2 && (sum2[2] % 400 == 0 || (sum2[2] % 4 == 0 && sum2[2] % 100 != 0)));

			else
				return -1;



		}
		else
		{
		 return -1;//month is invalid
		}
	}
	else
	{
		return -1;//year is invalid
	}













	//actual comparision : by comparing year month days respectively 
	while (i >= 0)
	{
		if (sum1[i] > sum2[i])  //sum1or2[2]=year ,sum1or2[1]=month ,sum1or2[0]=days
			return 2;  // person 2 is elder
		else if (sum1[i] < sum2[i])
			return 1; //person 1 is elder 
		else
			i--;   //equal hence compare next sum month ,day
	}
	return 0; //equal
	
}