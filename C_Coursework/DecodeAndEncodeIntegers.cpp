/*
Name: Gareth Warren
Date: 9/12/21
Class: CIT-145 Z01
IDE: Visual Studio 2019 Community Edition

A program that encodes and decodes a given 4 digit integer
If the number is 3 digits, it is assumed to begin with 0,
because 4 digit integers beginning with 0 are treated as octals

EncodeInteger adds 7 and takes the remainder after dividing by 10.
It then swaps first with third, second with fourth digit.

DecodeInteger adds 10 and then subtracts 7. 
It then swaps first with third, second with fourth digit.
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
# include <math.h>

//Global Constant
const int SIZE = 4;

//Returns the number of digits in a given number
int CountDigits(int number) {
	int counter = 0;

	while (number > 0) {
		number = number / 10;
		counter++;
	}
	return counter;
}

//Determine whether or not a number has three (begins with a 0) or four digits
bool CheckNumberIsThreeOrFourDigits(int number) {
	int checkDigits = 0;
	bool isThreeOrFourDigitNumber = false;

	checkDigits = CountDigits(number);

	if (checkDigits == 4 || checkDigits == 3) {
		isThreeOrFourDigitNumber = true;
	}

	return isThreeOrFourDigitNumber;
}

//Encode an Integer Value 
int EncodeInteger(int number) {
	int encodedNumber = 0;
	int integers[SIZE] = { 0,0,0,0 };
	int swappedIntegers[SIZE] = { 0,0,0,0 };
	int digit = 0;

	//Put digits into an array
	for (int index = SIZE - 1; index >= 0; index--) {
		if (CountDigits(number) == 3 && index == 0) {
			integers[0] = 0;
		}
		else {
			digit = number % 10;
			number = number / 10;
			integers[index] = digit;
		}
	}
	
	//Add 7 to each Digit. Digit is the modulus of Digit/10 
	digit = 0;
	for (int index = 0; index < SIZE; index++) {
		digit = integers[index];
		digit = digit + 7;
		digit = digit % 10;
		integers[index] = digit;
	}
	//Swap first and third, Swap second and fourth
	swappedIntegers[2] = integers[0];
	swappedIntegers[0] = integers[2];
	swappedIntegers[1] = integers[3];
	swappedIntegers[3] = integers[1];

	//Make Swapped values an Integer
	for (int index = 0; index < SIZE; index++) {
		encodedNumber = 10 * encodedNumber + swappedIntegers[index];
	}

	return encodedNumber;
}

//Decode an Integer Value
int DecodeInteger(int number) {
	int decodedNumber = 0;
	int index = 0;
	int digit = 0;

	int integers[SIZE] = { 0,0,0,0 };
	int swappedIntegers[SIZE] = { 0,0,0,0 };

	//Put digits into an array
	for (int index = SIZE - 1; index >= 0; index--) {
		
		if (CountDigits(number) == 3 && index == 0) {
			integers[0] = 0;
		}
		else {
			digit = number % 10;
			number = number / 10;
			integers[index] = digit;
		}
	}
	
	//Add 10 to Digit, then subtract 7. If digit is greater than 10, take modulus. 
	for (int index = 0; index < SIZE; index++) {
		digit = integers[index];

		digit = digit + 10 - 7;

		if (digit >= 10) {
			digit = digit % 10;
		}
		integers[index] = digit;
	}
	//Swap first and third, Swap second and fourth
	swappedIntegers[2] = integers[0];
	swappedIntegers[0] = integers[2];
	swappedIntegers[1] = integers[3];
	swappedIntegers[3] = integers[1];

	//Make Swapped values an Integer
	for (int index = 0; index < SIZE; index++) {
		decodedNumber = 10 * decodedNumber + swappedIntegers[index];
	}

	return decodedNumber;
}

//Main Program execution
int main() {
	int selection = 0;
	bool checkNumber = false;
	bool goAgain = false;
	int number = 0;

	do {
		//Get Encode or Decode
		printf("Encode (1) Decode (2):");
		if(scanf("%d", &selection));
		if (selection != 1 && selection != 2) {
			printf("Invalid Selection Choice: Exiting Program");
			exit(1);
		}
		printf("\n");
        
		//Get Number
		while (checkNumber == false) {
			printf("Enter a Four Digit Number:");
			
			//Validate User Input
			if (!scanf("%d", &number)) {
				printf("Input is not an Integer: Exiting Program");
				exit(1);
			};
			checkNumber = CheckNumberIsThreeOrFourDigits(number);
		}

		//Encode or Decode
		if (selection == 1) {

			number = EncodeInteger(number);
			if (CountDigits(number) == 3) {
				printf("Your Encoded Number is: 0%d \n", number);
			}
			else {
				printf("Your Encoded Number is: %d \n", number);
			}
		}
		else if (selection == 2) {
			number = DecodeInteger(number);
			if (CountDigits(number) == 3) {
				printf("Your Decoded Number is: 0%d \n", number);
			}
			else {
				printf("Your Decoded Number is: %d \n", number);
			}
		}

		checkNumber = false;

		//Continue entering numbers?
		printf("Continue(1) Exit(0):");
		
		if (scanf("%d", &selection)) {
			if (selection == 1) {
				goAgain = true;
			}
			else { 
				goAgain = false;
			}
		}
	} while (goAgain);

	return 0;
}