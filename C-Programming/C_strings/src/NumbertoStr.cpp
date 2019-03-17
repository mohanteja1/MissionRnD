/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/
#include <stdio.h>

int findlen(int num)
{
	int n = 0;
	while (num) {
		num /= 10;
		n++;
	}
	return n;
}
void number_to_str(float number, char *str,int afterdecimal){
	
	int negflag = 0, decflag = 1, intpart, i, n, k, decpart1, temp, prec = 1;
	if (number < 0)//if negative
	{
		number *= -1;
		negflag = 1;
		
	}

	float decpart;
	intpart = (int)number;
	decpart = number - intpart;
	if (decpart == 0)
		decflag = 0;

	for (int x = afterdecimal; x>0; x--)//precision of decimals
	{
		prec *= 10;
	};
	decpart1 = (int)((number - intpart)*prec);
	//length of digits
	i=findlen(intpart)+negflag;

	k = i-1;

	for (n = k; n >=0; n--)
	{
		temp = intpart %10;
		str[n] = temp + 48;
		intpart = intpart / 10;

	}




	if (decflag)
	{
		str[i] = '.';

		k = i + afterdecimal;

		while (k != i)
		{
			temp = decpart1 % 10;
			str[k] = temp + 48;
			decpart1 = decpart1 / 10;
			k--;
		}
		k = i + afterdecimal ;
	}
	k += 1;
	
	str[k] = '\0';
	if (negflag)
		str[0] = '-';
	printf("%s", str);
}
