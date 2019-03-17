/*
In this lesson you will be learning about void pointers , how to pass them, Why they are used etc.

Links : Just google "Void Pointers in C", (you can do the same in youtube too)

With void * as function parameter, you can pass address of any variable of any datatype. (By typecasting it to void*).
Lets say you wanted to write a sort function which sorts either list of ints, or floats or char etc.
You can write either 3 seperate quick sort functions 1 for each int sorting, float sorting and char sorting
or write a common quick sort function which takes void * array and can sort everything.

Void * are commonly used in conjuction with function pointers etc.
Yes I know most of you didnt understood a bit what I said, Lets learn this step by step.
Just go by task by task and patiently do it.
By the end of this lesson you are expected to have a good grip over void pointers and how to use them along side function
pointers.
*/
#include <stdio.h>
#include <stdlib.h>

/*
Void* is just a variable which can store address of any other variable (Irrespective of its dataType)
Task 5 :
-> Write a function which takes a void * ptr, and type cast it to int * and print its value.
Also return the int value stored in the ptr;
TLDR : Print and return the value printed.
*/

int typeCastVoidToInt(void * ptr) {
	printf("The value of integer variable is = %d\n", *((int*)ptr));
	return *(int*)ptr;
}

void task5() {
	int a = 5;
	printf("%d\n",typeCastVoidToInt((void *)&a));
}

/*
Task 6 :
-> Write a function which takes a  4 void * ptr.
You need to typecast each one to a different datatype pointer and print it.
Example For printing float ptr value:
printf("Value stored at floar_ptr is  %ld",*(float *)float_ptr);
Expected output:
Value stored at long_ptr is 7
Value stored at float_ptr is 8.3
Value stored at char_ptr is a
Value stored at str_ptr is voidpointers
*/

void typeCastToAllDataTypes(void * long_ptr, void * float_ptr, void * char_ptr, void * str_ptr) {
	printf("Value stored at long_ptr is %ld\n", *(long *)long_ptr);
	printf("Value stored at float_ptr is %f\n", *(float *)float_ptr);
	printf("Value stored at char_ptr is %c\n", *(char *)char_ptr);
	printf("Value stored at str_ptr is %s\n", *(char **)str_ptr);
	//Other code
}

void task6() {
	long a = 7;
	float b = 8.3;
	char c = 'a';
	char * d = "voidpointers";
	//Call typeCastToAllDataTypes with a,b,c,d . You need to find out
	typeCastToAllDataTypes((void *)&a, (void *)&b, (void *)&c, (void *)&d);
	//typeCastToAllDataTypes(&a, &b, &c, &d);
	
	//each variable address and then typecast to void * before passing.(Well for some just typecasting might be enough)
	


}

/*
Task 7 :
-> You are given 3 functions which each return a void *.
You need to call each of these functions, Typecast them to their respective datatype pointers,and print the values.
Expected output is
Float is 5.7
Int is 9
String is samplestring
*/

void * getFloatAsVoidStar() {
	/*
	What happens if you didnt use malloc and just declare a constant and return its address.Think.
	*/
	float *a = (float *)malloc(sizeof(float));
	*a = 5.7;
	return (void *)a;
	

	//float a = 9.4;
	//return (void *)&a;
}

void * getIntAsVoidStar() {
	int *a = (int *)malloc(sizeof(int));
	*a = 9;
	return (void *)a;
}

void * getStringAsVoidStar() {
	char * str = "samplestring";
	return (void *)str;
}

void task7() {
	//Call getFloatAsVoidStar,getIntAsVoidStar and getStringAsVoidStar and print their values.


 	printf("float value is:%f\n",*(float *)getFloatAsVoidStar());
	printf("int value is:%d\n",*(int *)getIntAsVoidStar());
	printf("string value is:%s\n",getStringAsVoidStar());


}


/*
Task 8 and 9  and 10: (These 3 tasks are related to each other)
-> First write 3 functions which compares either 2 ints or floats or chars and returns 1 if first parameter is greater
or 0 if equal or -1 if lesser.
Return type of these functions will be int, and parameters types will be void *. (You need to typecast and compare)

->Write a function which takes 2 void * values, and one compare function (which also takes 2 void *), and returns
address of which value is greater. (If equal return first address)
Ie .
This code sample should work
float val1 = 4;
float val2 = 5.5;
void * a = (void *)&val1;
void * b = (void *)&val2;
printf("Float : %f is greater between 4 and 5.5\n", *(float *)getGreater(a,b,&compareFloat));

ie .
getGreater uses compareFloat function to find which value is greater and then returns its address.
You need to typecast void * to float * and print it.

Note : See how void * function is declared and used in parameters, return types etc.
*/

int compareInt(void * a, void *b) {
	//Type cast to int *.extract value and compare
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int *)b)
		return -1;
	else
		return 0;
	
}

int compareFloat(void * a, void *b) {
	if (*(float*)a > *(float*)b)
		return 1;
	else if ( *(float*)a < *(float *)b)
		return -1;
	else
	return 0;
	
}

int compareChar(void * a, void *b) {
	//a and b hold only 1 character
	if (*(char*)a > *(char*)b)
		return 1;
	else if (*(char*)a < *(char *)b)
		return -1;
	else

	return 0;
}
//Optional Do for compareStrings also.
int compareString(void * s1, void *s2) {
	
	char *a = (char *)s1;
	char *b = (char *)s2;
	
	/*printf("%s", a);
	printf("%s", b);*/
	int c = 0;
	
	while (a[c] != 0 || b[c] != 0) {
		/*printf("%c\n", a[c]);
		printf("%c\n", b[c]);*/
		if (a[c]>b[c])
		{
        	return 1;

		}
		else if (a[c] < b[c])
		{
			return -1;
		}
	     
		c++;
	}

	if (a[c] == 0 && b[c] == 0)
	{
	
		return 0;
	}
	else if (a[c] == 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
void * getGreater(void *a, void *b, int(*compare)(void *, void *)) {

	//Use passed compare function.
	//printf("%d\n", compare(a, b));
	
	int i = compare(a, b);

	if (i == 1) 
		return a;
	else
		return b;
}

void task8() {
	float val1 = 4;
	float val2 = 5.5;
	void * a = (void *)&val1;
	void * b = (void *)&val2;
	//Passing compareFloat to getGreater as function pointer.
	printf("Float : %f is greater between 4 and 5.5\n", *(float *)getGreater(a, b, &compareFloat));
    
	char val3 = 'a';
	char val4 = 'z';
	void * a1 = (void *)&val3;
	void * b1 = (void *)&val4;
	printf("Char : %c is greater between a and z\n", *(char *)getGreater(a1, b1, &compareChar));

	//Optional do for strings too. Pass 2 strings to getGreater and print which is alphabatically before/after.
	char str1[] = "tejatoday";  //"mohanteja";
	char str2[] = "tejatomorrow";

	void * s1 = (void *)str1;
	void * s2 = (void  *)str2;
     printf("String : %d is greater between %s and %s\n",compareString(s1,s2), str1, str2);

	printf("String : %s is greater between %s and %s\n", (char *)getGreater((void *)str1,(void *) str2, &compareString),str1,str2);
}

/*
Same like above but with 3 void *, Use compareInt,compareFloat and compareChar functions to return addresses of 2 greater elements among the 3.
Write a function which finds out maximum 2 values in the passed 3 values and returns it as an array.
Parameters :
3 void *, and one function pointer to compare whether one void * is greater/lesser than other void *.

Return Type :
Array of 2 void *. result[0] will be a void * pointing to value which is greatest among 3, and
result[1] will be a void * pointing to next value which is greatest among 3.
Note :Compare the values not the addresses.

Assume all 3 values are unique.
Sample Input (Memory Layout):
[Address : 100] int a = 5; void * addr1 = (void *)&a;
[Address : 104] int b = 6; void * addr1 = (void *)&b;
[Address : 108] int c = 7; void * addr1 = (void *)&c;
So
addr1 : 100
addr2 : 104
addr3 : 108

Return an array which has addresses [108,104] (108 points to maximum value in the 3 passed values ie 7)
Assume each value is unique
*/
void ** getTwoGreater(void *addr1, void *addr2, void *addr3, int(*compare)(void *, void *)) {
	//Use malloc and create a array of 2 void *.
	void ** result = (void **)malloc(sizeof(void *) * 2);

	if (compare(addr1, addr2)>=0) //one is big
	{
		if (compare(addr2, addr3) == 1)  //two is big
		{
			result[0] = addr1;
			result[1] = addr2;
		}
		else
		if (compare(addr1, addr3) >= 0)
		{
			result[0] = addr1;
			result[1] = addr3;
		}
		else
		{
			result[0] = addr3;
			result[1] = addr1;
		}
	}
	else
	{
		if (compare(addr1, addr3) == 1)  //two is big
		{
			result[0] = addr2;
			result[1] = addr1;
		}
		else
			if (compare(addr2, addr3) >= 0)
			{
				result[0] = addr2;
				result[1] = addr3;
			}
			else
			{
				result[0] = addr3;
				result[1] = addr2;
			}
	}

	//Write your code here. You can use compare to know which value is greater between any 2 addresses.
	 //Assume if all void * are of float type, then compare function will also be a compareFloat one.

	return result;
}

void task9() {
	//Take 3 float values, pass those 3 variables addresses as void * to getTwoGreate function and print result[0],result[1];

	float value1 = 3.6;
	float value2 = 3.8;
	float value3 = 3.4;
	void * a = (void *)&value1;
	void * b = (void *)&value2;
	void * c = (void *)&value3;

	void ** result;
	result = getTwoGreater(a, b, c, &compareFloat);

	printf("the two greater numbers are : %f , %f \n", *(float *)result[0] , *(float *)result[1]);

	//Test the same for ints and char also.
     int  valu1 = 3;
	 int  valu2 = 4;
	int  valu3 = 3;
	void * a1 = (void *)&valu1;
	void * b2 = (void *)&valu2;
	void * c3 = (void *)&valu3;

	void ** resultInt;
	resultInt = getTwoGreater(a1, b2, c3, &compareInt);

	printf("the two greater numbers are : %d , %d \n", *(int *)resultInt[0], *(int *)resultInt[1]);


	char val1 = 'h';
	char val2 = 'h';
	char val3 = 'w';
	void * aC = (void *)&val1;
	void * bC= (void *)&val2;
	void * cC = (void *)&val3;

	void ** resultChar;
	resultChar = getTwoGreater(aC, bC, cC, &compareChar);

	printf("the two greater characters are : %c , %c\n", *(char *)resultChar[0], *(char	*)resultChar[1]);





}

/*
See previously instead of writing the same code 3 times for different data types where most of the code is same
, we solved it with a single function, and some datatype specific methods.

Lets now take this to next level. Solve MaxEqualSubSequence.cpp question.
*/
void test_voidpointers() {
	task5();
	task6();
	task7();
	task8();
	task9();
}