#define _CRT_SECURE_NO_WARNINGS

/*
Mock Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/

#include <stdio.h>
#include "FunctionHeaders.h"
#include<string.h>
#include<malloc.h>
struct CityNode{
	char city[20];
	struct CityNode * nextCity;
};

struct CityNode * createCityNode(char name[20]) {
	struct CityNode *newNode = (struct CityNode *)calloc(1, sizeof(CityNode));
	strcpy(newNode->city, name);
	newNode->nextCity = NULL;
	return newNode;
}

struct CityNode * createPath(char cities[][20], int len) {
	struct CityNode *head = NULL;

	for (int i = len - 1; i >= 0; i--){
		struct CityNode *newNode = createCityNode(cities[i]);
		newNode->nextCity = head;
		head = newNode;
	}
	return head;
}
int main(){

	//Test here
	/*
	long long start1 = 5, end1 = 100;
	long long start2 = 8, end2 = 8;
	int result = countCommonStars(start1,end1,start2,end2,55);

	printf("result = %d", result);
	*/
	/*int **snake = initialSnakePosition(5);

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			printf("%d - %d = %d\n", i, j, snake[i][j]);
		}
	}*/

	char cities1[][20] = { "A", "D", "K", "L", "M", "N", "O" };
	char cities2[][20] = { "Z", "X", "Q", "P", "D", "K", "L", "M", "N", "O" };
	CityNode *deepikaStartCity = createPath(cities1, 7);
	CityNode *mayaStartCity = createPath(cities2, 10);
	int numberOfCitiesMayaShouldTravel = 0;
	CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);
	printf("count %d", numberOfCitiesMayaShouldTravel);


	return 0;
}

