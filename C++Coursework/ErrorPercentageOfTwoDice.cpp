/*
Name: Gareth Warren
Date: 9/14/2121
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler

This program allows the user to roll any number of imaginary dice pairs.
It returns the error percentage based on the number of dice rolled, 
the results of adding the pair of dice together, and the odds of a rolling a specific total 
*/
#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//Function that returns a random number between 1 and 6 using rand
//Uses that number as one of two dice rolls, and returns the total 
int DiceRoll() {
	int diceRoll1 = rand() % 6 + 1;
	int diceRoll2 = rand() % 6 + 1;
	return diceRoll1 + diceRoll2;
}

//Calculate Odds, based on calculating a multiplier, the amount of dice rolled
//and the odds that one Dice Rolll of 2 dice will be a specific total
double CalculateOdds(int totalDice, int diceThatRolledSum, int sumTotal){
	double amountDice = (double)totalDice;
	double odds = 0.0;
	double multiplier = 0.0;

	switch(sumTotal){
	    case 2:
			odds = 1.0;
			break;
		case 3:
			odds = 2.0;
			break;
		case 4:
			odds = 3.0;
			break;
		case 5:
			odds = 4.0;
			break;
		case 6:
			odds = 5.0;
			break;
		case 7:
			odds = 6.0;
			break;
		case 8:
			odds = 5.0;
			break;
		case 9:
			odds = 4.0;
			break;
		case 10:
			odds = 3.0;
			break;
		case 11:
			odds = 2.0;
			break;
		case 12:
			odds = 1.0;
			break;
	}

	if(totalDice > 100){
	    while(amountDice > 100.0){
	        amountDice /= 10.0;
		    multiplier++;	
		}
	};
	multiplier = pow(10.0, multiplier);
	odds *= multiplier;

	return odds;
}
//Function that calculates the error based on number of rolls of 2 dice
//Subtract number of rolled dice results from their Odds, flip the negative if applicable, divide by Odds
double CalculateError(int diceThatRolledSum, double odds){
	double error = 0;
     
	error = odds - (double)diceThatRolledSum;
	if(error < 0){
		error *= -1;
	}
	error /= odds;
	error *= 100;

	return error;
}

int main() {
	//seed rand()
	srand(time(NULL));
	//Info Arrays
	const int Sum[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int DiceCounter[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double ErrorPercentage[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double Odds[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	//Constants
	const int SIZE = 11;
	const int MAX_INT = 2147483647;
	//Variables
	int numberOfDiceRolls = 0;
	int rollResult = 0;
	int selection = 0;
	//Validation
	int validEntry = 0;
	//Loop Control
	bool goAgain = false;

	do{
		//Ask the user how much dice they want to roll and verify input
		printf("Please Enter the number of rolls you want: ");
		validEntry = scanf("%d", &numberOfDiceRolls);
		printf("\n");
		if(validEntry == 0 || numberOfDiceRolls >= MAX_INT){
			printf("Invalid Entry: Exiting Program");
	     	exit(1);
		}
	    //get number of dice that rolled a specific total
        for(int rolls = 1; rolls <= numberOfDiceRolls; rolls ++){
            rollResult = DiceRoll();
		    switch(rollResult){
			    case 2:
			        DiceCounter[0]++;
			        break;
			    case 3:
                    DiceCounter[1]++;
			        break;
			    case 4:
			        DiceCounter[2]++;
			        break;
			    case 5:
			        DiceCounter[3]++;
			        break;
			    case 6:
			        DiceCounter[4]++;
			        break;
			    case 7:
			        DiceCounter[5]++;
			        break;
			    case 8:
			        DiceCounter[6]++;
			        break;
			    case 9:
			        DiceCounter[7]++;
			        break;
			    case 10:
			        DiceCounter[8]++;
			        break;
			    case 11:
			        DiceCounter[9]++;
			        break;
				case 12:
					DiceCounter[10]++;
					break;
			}
		}
		//Get Errors
		for(int index = 0; index < SIZE; index ++){
            Odds[index] = CalculateOdds(numberOfDiceRolls, DiceCounter[index], Sum[index]);
		}
		for(int index = 0; index < SIZE; index ++){
		    ErrorPercentage[index] = CalculateError(DiceCounter[index], Odds[index]);
		}
		
		//Tabulate Results
        printf("Sum: \t\tRolled Pairs: \tOdds: \tError Percentage\n");
		for(int index = 0; index < SIZE; index ++){
			printf("%3d: %15d %15.0f %15.4f \n", Sum[index], DiceCounter[index], Odds[index], ErrorPercentage[index]);
		}

		//Ask to go Again
		printf("Do you want to go Again? (1 = Yes, 0 = Exit)");
		validEntry = scanf("%d", &selection);
		if(selection == 1 && validEntry != 0){
			goAgain = true;
			for(int index = 0; index < SIZE; index ++){
				DiceCounter[index] = 0; 
				Odds[index] = 0.0;
				ErrorPercentage[index] = 0.0;
			}
		}else{
			goAgain = false;
		}
	}while(goAgain);
	printf("Exiting Program.\n");

	system("pause"); 
	return 0;
}