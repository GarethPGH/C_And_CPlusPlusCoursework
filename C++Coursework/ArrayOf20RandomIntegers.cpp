/*
Name: Gareth Warren
Date: 9/18/2121
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler

Program generates an array of 20 random integers between 1, and 10.
It counts the occurance of each integer, 
outputs the contents of the sorted array, and how many of each integer are in it
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <regex>

using namespace std;

//Function that generates random numbers between 1 and 10
int GetRandomNumber(){
    int random = rand()%10 + 1;
    return random;
}

int main(){
    srand(time(NULL));
    int numbers[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int count[] = {0,0,0,0,0,0,0,0,0,0};
    const int integer[] = {1,2,3,4,5,6,7,8,9,10};
    const int NUM_SIZE = 20;
    const int INT_COUNT_SIZE = 10;
    int selection = 0;
    bool goAgain = false;
    int input = 0;
    regex integer_expr("(-)?[[:digit:]]+");
    string placeholder = "";
   
    cout << "This program generates random numbers and tabulates the results\n";

    do{
        for(int &number : count){
            number = 0;
        }
        //fill the array with random numbers
        for(int &number: numbers){
            number = GetRandomNumber();
        }
        cout << "Original List:\n";
        for(int number: numbers){
            cout << number << ", ";
        }

        //Sort the Array
        sort(numbers, numbers + 20);

        //Output occurances of each value
        for(int number: numbers){
            switch(number){
                case 1:
                    count[0]++;
                    break;
                case 2:
                    count[1]++;
                    break;
                case 3:
                    count[2]++;
                    break;
                case 4:
                    count[3]++;
                    break;
                case 5:
                    count[4]++;
                    break;
                case 6:
                    count[5]++;
                    break;
                case 7:
                    count[6]++;
                    break;
                case 8:
                    count[7]++;
                    break;
                case 9:
                    count[8]++;
                    break;
                case 10:
                    count[9]++;
                    break;
                default:
                    break;
            }
        }

        //Print results
        cout << "\n\nSorted List:\n";
        for(int number: numbers){
            cout << number << ", ";
        }

        cout << "\n\nNumber Count:\n";
        for(int index = 0; index < INT_COUNT_SIZE; index++){
            cout << integer[index] << ": " << count[index] << endl;
        }

        //Ask to go again
        cout << "Try Again? (1 = yes, 0 = exit)" << endl;
        
        getline(cin, placeholder);
    
        if(regex_match(placeholder, integer_expr)){
            input = stoi(placeholder);
            if(input == 1){
                goAgain = true;
            }else{
                goAgain = false;
            }
        }else{
            cout << "Invalid Selection: Exiting Program\n";
            exit(1);
        }
    }while(goAgain);
    cout << "Exiting Program." << endl;

    system("pause");
    return 0;
}

