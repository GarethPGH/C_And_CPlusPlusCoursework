/*
Name: Gareth Warren
Date: 9/14/2121
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler

This program calculates the greatest common denominator of a fraction
and returns the fraction reduced to its lowest terms.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <regex>
#pragma warning(disable: 4996)

using namespace std;

//function that returns the greatest common denominator
//given a specific numerator, and denominator
int gcd(int numerator, int denominator){
    int greatestCommonDenominator = 0;
    int temp = 0;
    while (denominator != 0){
        temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }
    greatestCommonDenominator = numerator;
    return greatestCommonDenominator;
}
//function that reduces a given numerator and denominator 
//by using the greatest common denominator of the terms
void reduce(int &numerator, int &denominator){
    int lowestCommonDen = gcd(numerator, denominator);
    numerator = (double)numerator/(double)lowestCommonDen;
    denominator = (double)denominator/(double)lowestCommonDen;
}

//Verify user Integer input. Return Integer, or Exit Program if invalid
int VerifyInput(string message){
    string placeholder = "";
    int input = 0;
    regex integer_expr("(-)?[[:digit:]]+");
    
    getline(cin, placeholder);
    
    if(regex_match(placeholder, integer_expr)){
        input = stoi(placeholder);
    }else{
        cout << message;
        exit(1);
    }

    return input;
}

int main(){
    bool goAgain = false;
    int selection = 0;
    int greatestCommonDenominator = 0;
    int numerator = 0;
    int denominator = 0;
    regex integer_expr("(-)?[[:digit:]]+");
    string placeholder = "";
    string message = "";

     cout << "This program takes a numerator and denominator and reduces to lowest terms" << endl;
    do{
        cout << "Enter the Numerator: ";
        message = "Invalid Numerator: Exiting Program\n";
        numerator = VerifyInput(message);
        
        cout << "\nEnter the Denominator: ";
        message = "Invalid Denominator: Exiting Program\n";
        denominator = VerifyInput(message);
        cout << endl;

        greatestCommonDenominator = gcd(numerator, denominator);
        reduce(numerator, denominator);

        cout << "The Greatest Common Denominator is: " << greatestCommonDenominator << endl;
        cout << "Your fraction reduced is: " << numerator << "/" << denominator << endl; 
        cout << "Try Again? (1 = yes, 0 = exit)" << endl;
        
        message = "Invalid Selection: Exiting Program\n";
        selection = VerifyInput(message);
            
        if(selection == 1){
            goAgain = true;
        }else{
            goAgain = false;
        }
    }while(goAgain);

    cout << "Exiting Program." << endl;

    system("pause"); 
	return 0;
}