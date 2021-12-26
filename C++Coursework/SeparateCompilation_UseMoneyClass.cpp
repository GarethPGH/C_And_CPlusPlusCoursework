/*
Name: Gareth Warren
Date: 9/30/21
Class: CIT-245 Z01
IDE: Visual Studio 2019 Community Edition

Program that demonstrates the Money class in file Money.h
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "Money.h"

using namespace std;

int main(){
    double amount = 0;
    Money money1 = 0;
    Money money2 = 0;
    bool comparison = false;

    cout << "Enter an Amount of Money\n";
    cin >> amount;
    money1 = Money(amount);
    cout << "Enter another amount of Money\n";
    cin >> amount;
    money2 = Money(amount);
    comparison = money1 < money2;
    if(comparison){
        cout << "Amount1 is less than Amount2\n";
    }else{
        cout << "Amount1 is not less than Amount2\n";
    }   
    comparison = money1 > money2;
    if(comparison){
        cout << "Amount1 is greater than Amount2\n";
    }else{
        cout << "Amount1 is not greater than Amount2\n";
    }
    comparison = money1 == money2;
    if(comparison){
        cout << "Amount1 is equal to Amount2\n";
    }else{
        cout << "The amounts are not equal.\n";
    }
    cout <<"Amount 1: " << money1 << " Amount2: " << money2 << endl; 
    printf( "Amount 2 is %.2f percent of Amount1\n" , money1.percentage(money1, money2)); 
    
    Money money3;

    cout << "Enter another amount of Money. Please remember to include a $ sign\n";

    cin >> money3;

    cout << "Your Amount: " << money3;
    
    money3 = -money3;
    
    cout << " Your amount is now negative: " << money3 << endl; 

    system("pause");
    return 0;
}