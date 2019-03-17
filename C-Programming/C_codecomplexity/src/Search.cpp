/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

For 100000 times, Array size 1000  Took 0.855000 seconds in  linear search
For 100000 times, Array size 10000 Took 7.776000 seconds in  linear search
For 100000 times, Array size 100000 Took 70.408000 seconds in  linear search

Binary Search :
For 100000 times, Array size 1000 Took 0.021000 seconds in binary search
For 100000 times, Array size 10000 Took 0.031000 seconds in binary search
For 100000 times, Array size 100000 Took 0.032000 seconds in binary search


Conclusion :
binary search is the best search algorithm 

*/

int linearSearch(int *arr, int len, int key) {
	int i;
	for (i = 0; i <= len; i++)
	{
		if (arr[i] > arr[i + 1])
			return -1;
	
		if (arr[i] == key)
			return i;
	
	}

	return -1;
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	
	int lowbd = 0, highbd = len - 1, midp, datalocation;
	
	//binary search
	while (lowbd <= highbd)
	{

		midp = lowbd + (highbd - lowbd) / 2;


		if (arr[midp] == key)
		{
			datalocation = midp;
			return datalocation;
		}
		else
		{
			if (arr[midp] < key)
			{

				lowbd = midp + 1;
			}
			else
			{
				highbd = midp - 1;
			}
		}
	}
	return -1;
}