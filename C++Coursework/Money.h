/*
Name: Gareth Warren
Date: 9/30/21
Class: CIT-245 Z01
IDE: Visual Studio 2019 Community Edition

Money.h class that creates Money Objects and overloads several operators
*/
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

class Money{
    private:
        int dollars;
        int cents;
        //Convert dollars from double
        int dollarsPart(double amount){
            return static_cast<int>(amount);
        };
        //Convert cents from double
        int centsPart(double amount){
            double doubleCents = amount * 100;
            int intCents = (round(fabs(doubleCents))) % 100;

            if(amount < 0){
                intCents = -intCents;
            }
            return intCents;
        };
        //rounding function
        int round(double number) {
            return static_cast<int>(floor(number + 0.5));
        }
    
    public: 
        //Constructors
        Money(){
            dollars = 0;
            cents = 0;
        }
        Money(double money){
            dollars = dollarsPart(money);
            cents = centsPart(money - (double)dollars);
        }
        Money(int dollars, int cents){
            if(dollars < 0 && cents > 0 || dollars > 0 && cents < 0){
                cout << "Inconsistent Money Data\n";
                exit(1);
            }
            this-> dollars = dollars;
            this-> cents = cents;
        }
        Money(int dollars){
            dollars = dollars;
            cents = 0;
        }

        //Accessors
        //Get Total Amount of Money as double
        double getAmount(){
            return (((dollars*100) + cents) * 0.01);
        }
        //Get Dollar Amount
        int getDollars(){
            return dollars;
        }
        //Get Cents Amount
        int getCents(){
            return cents;
        }

        //Percentage Method to compare two amounts of money
        double percentage(Money amount1, Money amount2){
            return (amount2.getAmount() / amount1.getAmount()) * 100;
        }
    
//Overloaded Operators      
        friend ostream& operator << (ostream& outputStream, const Money &amount);
        friend istream& operator >> (istream& inputStream, const Money &amount);
        friend const Money operator + (Money &amount1, Money &amount2);
        friend const Money operator - (const Money &amount1, const Money &amount2);
        friend bool operator == (const Money &amount1, const Money &amount2);
        friend const Money operator -(const Money &amount);
        friend bool operator < (const Money &amount1, const Money &amount2);
        friend bool operator > (const Money &amount1, const Money &amount2);
};

//Overloaded Operators
//Return a Money object with 2 money amounts added
const Money operator + (Money& amount1, Money& amount2){
    int allCents1 = amount1.getCents() + (amount1.getDollars() * 100);
    int allCents2 = amount2.getCents() + (amount2.getDollars() * 100);
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if(sumAllCents < 0){
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
}

//Return a Money object with 2 money amounts subtracted
const Money operator - (Money &amount1, Money &amount2){
    int allCents1 = amount1.getCents() + (amount1.getDollars() * 100);
    int allCents2 = amount2.getCents() + (amount2.getDollars() * 100);
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if(diffAllCents < 0){
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
}

//Return whether two Money objects are equal     
bool operator == (Money &amount1, Money &amount2){
    return ((amount1.getDollars() == amount2.getDollars() && amount1.getCents() == amount2.getCents()));
}

//Return a Money Object with Reversed amount (flip a positive value to negative, or negative to positive) 
const Money operator - (Money &amount){
    double amt = amount.getAmount();
    return Money(-amt);
}

//Return whether Money object 1 is less than Money object 2
bool operator < (Money &amount1, Money &amount2){
    int totalCents1 = (amount1.getDollars() * 100) + amount1.getCents();
    int totalCents2 = (amount2.getDollars() * 100) + amount2.getCents();
            
    if(totalCents1 < totalCents2){
        return true;
    }else{
        return false;
    }
}

//Return whether Money object1 is greater than Money Object 2
bool operator > (Money &amount1, Money &amount2){
    int totalCents1 = (amount1.getDollars() * 100) + amount1.getCents();
    int totalCents2 = (amount2.getDollars() * 100) + amount2.getCents();
            
    if(totalCents1 > totalCents2){
        return true;
    }else{
        return false;
    }
}
//<< Operator to Output Money Object
ostream& operator << (ostream &outputStream, Money &amount){
    int absDollars = abs(amount.getDollars());
    int absCents = abs(amount.getCents());
    if(amount.getDollars() < 0 || amount.getCents() < 0){
        cout << "$-";
        cout << absDollars;
    }else{
        cout << "$"; 
        cout << absDollars;
    }
    if(absCents >= 10){
        cout << "." << absCents;
    }else{
        cout << "." << "0" << absCents;
    }
    return outputStream;
}
//>> Operator to Input Money Object
istream& operator >> (istream &inputStream, Money &amount){
    char dollarSign;
    cin >> dollarSign;
    if(dollarSign != '$'){
        cout << "No dollar sign in money input\n";
        exit(1);
    }

    double amountAsDouble;
    cin >> amountAsDouble;
    amount = Money(amountAsDouble);
    return inputStream;
}