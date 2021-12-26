/*
Name: Gareth Warren
Date: 9/14/2121
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler

Program that Calculates interest on a $1000.00 amount for 10 years
at an interest rate starting at 5%, increasing in 1% increments to 10%.
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>


int main(){
double interestRate = 0.05;
double loanAmount = 1000.0;

printf("Interest on $1000.00 over 10 years\n");
printf("Rate   Total\n");

for(int interestIncrement = 1; interestIncrement <= 6; interestIncrement++){
    for(int year = 1; year <= 10; year++){
        loanAmount = (interestRate * loanAmount) + loanAmount;
    }
    printf("%3.2f  $%7.2f\n", interestRate, loanAmount);
    
    interestRate += 0.01;
    loanAmount = 1000.0;
}

system("pause"); 
return 0;
}