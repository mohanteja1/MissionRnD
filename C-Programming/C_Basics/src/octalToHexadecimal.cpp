/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/


#include<stdlib.h>
#include<math.h>

int decflag1 = 0, decflag2 = 0;
int stringToInteger(char *numstr)
{
	int x, num = 0;
	while (*numstr != '\0'){
		x = (int)*numstr - 48;
		num = num * 10 + x;
		*numstr++;
	}

	return num;
}
char * concantenation(char *dest, const char *src)
{
	size_t i, j;
	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return dest;
}

int octalToHexadecimal(long int num)
{
	int octal[] = { 0, 1, 10, 11, 100, 101, 110, 111 };
	int i, n, hexnum;
	char *reverse;
	long long octald, tempOctal, binary, place;

	char hex[65] = "";
	int rem;

	place = 1;
	binary = 0;


	tempOctal = (long)num;

	while (tempOctal > 0)
	{
		rem = tempOctal % 10;
		binary = (octal[rem] * place) + binary;
		tempOctal /= 10;

		place *= 1000;
	}
	//for fraction conversion usage
	if (decflag1)
	{
		if (decflag2)
			binary = (1000000 + binary) * 100;
		else
			binary = binary * 100;
	}




	while (binary > 0)
	{
		rem = binary % 10000;
		switch (rem)
		{
		case 0:
			concantenation(hex, "0");
			break;
		case 1:
			concantenation(hex, "1");
			break;
		case 10:
			concantenation(hex, "2");
			break;
		case 11:
			concantenation(hex, "3");
			break;
		case 100:
			concantenation(hex, "4");
			break;
		case 101:
			concantenation(hex, "5");
			break;
		case 110:
			concantenation(hex, "6");
			break;
		case 111:
			concantenation(hex, "7");
			break;
		case 1000:
			concantenation(hex, "8");
			break;
		case 1001:
			concantenation(hex, "9");
			break;
		case 1010:
			concantenation(hex, "A");
			break;
		case 1011:
			concantenation(hex, "B");
			break;
		case 1100:
			concantenation(hex, "C");
			break;
		case 1101:
			concantenation(hex, "D");
			break;
		case 1110:
			concantenation(hex, "E");
			break;
		case 1111:
			concantenation(hex, "F");
			break;
		}

		binary /= 10000;
	}



	//reversing the obtained string
	for (i = 0; hex[i] != '\0'; i++)
		;


	reverse =(char*) malloc(i*sizeof(char));
	n = i - 1;

	for (i = n; i >= 0; i--)
		reverse[n - i] = hex[i];

	reverse[n + 1] = '\0';


	//string to num
	hexnum = stringToInteger(reverse);



	return  hexnum;
}
float octalToHexadecimalFraction(float num)
{ 

	// brute force || not

	int hexfrac, decint, hexint, intpart = (int)num;
	double decpart = num - intpart;//extracting fractional part


	hexint = octalToHexadecimal(intpart);

	decpart = round(decpart*100.0);//until precision 2


	decint = (int)decpart;



	  decflag1 = 1;// making octalToHexadecimal() suitable to fractional part

	if (decint<8)  //if fractional part <0.08
		decflag2 = 1;

	hexfrac = octalToHexadecimal(decint);
	if (decflag2)
		hexfrac = hexfrac % 100;

	decflag2 = decflag1 = 0;

//combining decimal and fractional parts
	return (float)hexint + (float)(hexfrac / 100.0);

}