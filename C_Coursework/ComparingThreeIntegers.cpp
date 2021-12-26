/* 
Name: Gareth Warren
Date: 8/28/21
Class: CIT-145 Z01
IDE: Visual Studio 2019 Community Edition

A program that inputs three integersand outputs the smallest, the largest, the sum
and the average.*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>

// Adds three Integers and returns a Sum
int CalculateSum(int firstNum, int secondNum, int thirdNum) {
	int sum = firstNum + secondNum + thirdNum;
	return sum;
}

//Given a previous Total, divide that number by number of Integers that were added
double CalculateAverage(int addedTotal, int numberOfInts) {
	double average = 0.0;
	average = (double)addedTotal / (double)numberOfInts;
	return average;
}

//Given three Integers, return the Largest Integer
int FindLargest(int firstNum, int secondNum, int thirdNum){
	int largest = -1;
	if (firstNum > secondNum && firstNum > thirdNum) {
		largest = firstNum;
	}
	else if (secondNum > firstNum && secondNum > thirdNum) {
		largest = secondNum;
	}
	else if (thirdNum > secondNum && thirdNum > firstNum) {
		largest = thirdNum;
	}

	return largest;
}

//Given three Integers, return the Smallest Integer
int FindSmallest(int firstNum, int secondNum, int thirdNum) {
	int smallest = -1;
	if (firstNum < secondNum && firstNum < thirdNum) {
		smallest = firstNum;
	}
	else if (secondNum < firstNum && secondNum < thirdNum) {
		smallest = secondNum;
	}
	else if (thirdNum < secondNum && thirdNum < firstNum) {
		smallest = thirdNum;
	}

	return smallest;
}


int main() {
	//inputs
	int integer1 = 0;
	int integer2 = 0;
	int integer3 = 0;

	//outputs
	int sum;
	int largest;
	int smallest;
	double average;

	printf("Please enter the first integer value\n");
	scanf("%d", &integer1);

	printf("Please enter the second integer value\n");
	scanf("%d", &integer2);

	printf("Please enter the third integer value\n");
	scanf("%d", &integer3);
	
	//Calculate sum
	sum = CalculateSum(integer1, integer2, integer3);
	//Calculate average
	average = CalculateAverage(sum, 3);
	//Assign largest
	largest = FindLargest(integer1, integer2, integer3);
	//Assign smallest
	smallest = FindSmallest(integer1, integer2, integer3);


	printf("Your numbers are: %d %d %d \n", integer1, integer2, integer3);
	printf("The Sum is: %d \n", sum);
	printf("The Average is: %.3f \n", average);
	if (smallest == -1) {
		printf("There is no Smallest Number.\n");
	}
	else {
		printf("The Smallest Number: %d \n", smallest);
	}
	if (largest == -1) {
		printf("There is no Largest Number.\n");
	}
	else {
		printf("The Largest Number: %d \n", largest);
	}

	system("pause");
	return 0;
}