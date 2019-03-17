/*
OVERVIEW:
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	//using recursion
	if (num < 0)
		return 0;

	if (num <= 8)
		return num;
	else
		return ((decimalToOctal(num / 8) * 10 )+ (num % 8));
}

float decimalToOctalFraction(float num)
{
	int frac = 0, presicion = 2;

	int n = presicion, octaint, intpart1, intpart = (int)num;
	octaint = decimalToOctal(intpart);
	double octalfrac, decpart = num - intpart;

	while (presicion--)
	{

		decpart = decpart * 8;
		frac = frac * 10 + (int)decpart;
		intpart1 = (int)decpart;
		if (decpart>1)
		{
			decpart = decpart - intpart1;
			n++;

		}
	

	}


	return (float)octaint + (float)frac / 100.0/*pow(10,n)*/;
}