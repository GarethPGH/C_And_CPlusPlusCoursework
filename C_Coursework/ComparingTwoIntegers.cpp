/*
Name: Gareth Warren
Date: 8/28/21
Class: CIT-145 Z01
IDE: Visual Studio 2019 Community Edition

A program that inputs two Integers and outputs the Larger of the two
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>

int main() {
	//inputs
	int integer1 = 0;
	int integer2 = 0;

	printf("Please enter the first integer value\n");	
	scanf("%d", &integer1);

	printf("Please enter the second integer value\n");
	scanf("%d", &integer2);

	if (integer1 > integer2) {
		printf("%d is greater than %d \n", integer1, integer2);
	}
	else if (integer2 > integer1) {
		printf("%d is greater than %d \n", integer2, integer1);
	}
	else if (integer1 == integer2) {
		printf("Both numbers are equal to each other\n");
	}
	else {
		printf("Something else happened\n");
	}

	system("pause");
	return 1;
}