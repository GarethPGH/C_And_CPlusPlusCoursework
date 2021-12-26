/*
Name: Gareth Warren
Date: 10/28/2121
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Program that implements a recursive algorithm solution, using stacks, to simulate the game 
Towers of Hanoi: three poles are used to move discs of increasing size from the first to third pole, 
and no disc can sit on a smaller disc
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <math.h>

using namespace std;

void DoTowersOfHanoi(int discs, stack<int> start, stack<int> middle, stack<int> finish, string stackName1, string stackName2){
    if(discs == 1){
        //Base case number of disc = 1
        start.pop();
        finish.push(discs);
        cout << "Moving disc from " << stackName1 << " to " << stackName2 << endl;
        return;
    }else{
        //Move n-1 disc from start to middle, using finish to hold discs
        DoTowersOfHanoi(discs-1, start, middle, finish, "1", "2");
        
        //Move top from start to finish
        DoTowersOfHanoi(1, start, finish, middle, "1", "3");
        
        //Move n-1 disc from middle to finish, using start to hold discs
        DoTowersOfHanoi(discs-1, middle, finish, start, "2", "3");
        
        discs--;
    }
}

int main(){

    stack<int> start;
    stack<int> middle;
    stack<int> finish;
    int numberOfMoves;
    
    int discs;
    string userInput;
    bool goAgain = true;

    do{
        //Ask user how many discs to use
        cout << "Enter the number of Discs to use:";
        cin >> userInput;
        cout << endl;
        
        //Create Stack of discs where larger discs are on the bottom
        //Play the game
        if(strlen(userInput.c_str()) == 1  && isdigit(userInput[0])){
            discs = stoi(userInput);
            for(int disc = discs; disc >= 1; disc--){
                start.push(disc);
            } 

            DoTowersOfHanoi(discs, start, middle, finish, "1", "3");
            
            numberOfMoves = pow(2, discs) -1;
            cout << "Number of Moves: " << numberOfMoves << endl;
        }else{
            cout << "Invalid input, try again." << endl;
        }
        
        //Go Again?
        userInput = "";
        cout << "Do you want to go again? Yes, or Y to continue, anything else to exit." << endl;
        cin >> userInput;
        const char* input = userInput.c_str();
        if(userInput.empty() || strlen(input) < 1 || strlen(input) > 3){
            cout << "Exiting Program..." << endl;
            goAgain = false;
        }else{
            if(strcmp(input, "Yes") == 0 || strcmp(input, "Y") == 0 || strcmp(input, "yes") == 0 || strcmp(input, "y") == 0){
                goAgain = true;
            }else{
                cout << "Exiting Program..." << endl;
                goAgain = false;
            }
        }
    }while(goAgain);

    system("pause");
    return 0;
}