/*Name: Gareth Warren
* Date: 9/3/2021
* Class: CIT 245 Z01
* 
* This program applies the Babylonian Square Root algorithm to estimate the square root of any given number
* User prompts allow the user to interact with the program and supply as many numbers as they please
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//Function applies the Babylonian Square Root algorithm
double BabylonianSquareRoot(double number){
	//Variables
	double guess = 0.0;
	double r = 0.0;
	double input = number;
	bool loopControl = true;
	double numberCheck = 1.0;

	//Logic
	guess = input / 2.0;

	while (loopControl == true) {
		r = input / guess;
		guess = (guess + r)/2.0;

		cout << "Guessing ... " << guess << endl;

		numberCheck = number - (guess * guess);

		if (numberCheck <= 0.001 && numberCheck >= -0.001) {
			loopControl = false;
		}
	}

	return guess;
}

//Main
int main(){
	//Input
	double number = 0;

	//Loop Control
	bool goAgain = false;

	//Check
	string selection = "";

	do {
		cout << "Enter a number and I will apply the Babylonian square root algorithm until I am within .001 of the correct answer.\n";
		cin >> number;
		cout << "You entered " << number << endl;

		number = BabylonianSquareRoot(number);

		cout << "The Babylonian Square Root Algorithm gives " << number << endl;

		cout << "Checking: " << number << " * " << number << " = " << number * number << endl;

		cout << "Do you want to find another square root?\n";

		cin >> selection;

		if (selection == "yes" || selection == "Yes" || selection == "YES" || selection == "Y" || selection == "y") {
			goAgain = true;
		}
		else {
			cout << "Exiting Program\n";
			goAgain = false;
		}
	}while (goAgain);

	system("pause");

	return 1;
}