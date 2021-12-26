/*
Name: Gareth Warren
Date: 10/8/21
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Program that uses the STL Stack to Reverse a String
*/


#pragma warning(disable: 4996)

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    const int SIZE = 80;
    stack<char> reverseString;
    char* inputString = (char *)malloc(SIZE);
    string placeholder = "";
    int selection = 1;
    

    cout << "This program reverses a string using the STL stack" << endl;
    
    while(selection == 1){
        cout << "Enter your string of less than 80 characters followed by an ENTER\n" << endl;
        cin.getline(inputString, SIZE + 1,'\n');
        
        //Push the Value of inputString onto Stack, and Move Pointer
        while(*inputString != '\0'){
            reverseString.push(*inputString);
            inputString++;
        }
        //Display the contents of the Stack; reversing the string
        while(!reverseString.empty()){
            cout << reverseString.top();
            reverseString.pop();
        }
        cout << "\n\nEnter another? 1 = continue. Anything else to stop" << endl;
        
        //To avoid crashing at end of program with non integer input
        getline(cin, placeholder);
        try {
            selection = stoi(placeholder);
            if(selection != 1){
                cout << "Exiting Program\n";
                exit(1);
            }
        }catch(const invalid_argument &e){
            cout << "Exiting Program\n";
            exit(1);
        } 
    }

    free(inputString);
    
    system("pause");
    return 0;
}