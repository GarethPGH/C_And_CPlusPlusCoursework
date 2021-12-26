/*
Name: Gareth Warren
Date: 10/14/21
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

WrapArrayDeep and WrapArrayShallow Classes with added Display and ChangeValues functions 
Demonstrate the use of pointers as arrays, the Copy Constructor, and Destructor methods 
that were introduced in Chapter 10
*/
#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class WrapArrayDeep{
    private:
        char *pch;
        const int SIZE = 5;
    public: 
        WrapArrayDeep();
        WrapArrayDeep(const WrapArrayDeep &wad);
        void DisplayDeepArray();
        void ChangeValues();
        ~WrapArrayDeep();
};


class WrapArrayShallow{
    private:
        char *pch;
        const int SIZE = 5;
    public:
        WrapArrayShallow();
        WrapArrayShallow(const WrapArrayShallow &was);
        void DisplayShallowArray();
        void ChangeValues();
        ~WrapArrayShallow(); 
};


//Normal Constructor    
WrapArrayDeep::WrapArrayDeep(){
    cout << "Called WrapArrayDeep Constructor. Array Created" << endl;
    pch = new char[SIZE];
    *pch = 86; 
    *(pch + 1) = 87;
    *(pch + 2) = 88;
    *(pch + 3) = 89;
    *(pch + 4) = 90;
}
//Correct Copy Constructor
WrapArrayDeep::WrapArrayDeep(const WrapArrayDeep &wad){
    cout << "Called WrapArrayDeep Copy Constructor. Deep Copy Created." << endl;
    this -> pch = new char[SIZE];
    for(int index = 0; index < SIZE; index++){
        pch[index] = wad.pch[index];
    }
}
//Display Function
void WrapArrayDeep::DisplayDeepArray(){
    
    for(int index = 0; index < SIZE; index++){
        if(index == SIZE-1){
            cout << pch[index] << endl;
        }else{
            cout << pch[index] << ", ";
        }
    }
}
//Change Values
void WrapArrayDeep::ChangeValues(){
     *pch = 65; 
    *(pch + 1) = 67;
    *(pch + 2) = 68;
    *(pch + 3) = 69;
    *(pch + 4) = 70;
}
//Destructor
WrapArrayDeep::~WrapArrayDeep(){
    cout << "Called Destructor WrapArrayDeep. Array Deleted" << endl;
    delete[] pch;
}



//Normal Constructor
WrapArrayShallow::WrapArrayShallow(){
    cout << "Called WrapArrayShallow Constructor. Array Created" << endl;
    pch = new char[5];
    pch[0] = 86; 
    pch[1] = 87;
    pch[2] = 88;
    pch[3] = 89;
    pch[4] = 90; 
}
//Incorrect Copy Constructor
WrapArrayShallow::WrapArrayShallow(const WrapArrayShallow &was){
    cout << "Called WrapArrayShallow Copy Constructor. Shallow Copy Created." << endl;
    this->pch = was.pch;
}
//Display Function
void WrapArrayShallow::DisplayShallowArray(){
    
    for(int iterator = 0; iterator < SIZE; iterator++){
        if(iterator == SIZE-1){
            cout << *pch << endl;
        }else{
            cout << *pch << ", ";
        }
        pch++;
    }
}
//Change Values
void WrapArrayShallow::ChangeValues(){
    pch[0] = 65; 
    pch[1] = 67;
    pch[2] = 68;
    pch[3] = 69;
    pch[4] = 70;
}
//Destructor 
WrapArrayShallow::~WrapArrayShallow(){
    cout << "Called Destructor WrapArrayShallow."  << endl;
    //This does not prevent error when the array pointed to Shallow Array is deleted already
    if(this -> pch == NULL){
        cout << "ERROR: Array already deleted. Returning to main." << endl;
        return;
    }else{
        delete[] pch;
        cout << "Array Deleted." << endl;
        this -> pch = NULL;
    }
}