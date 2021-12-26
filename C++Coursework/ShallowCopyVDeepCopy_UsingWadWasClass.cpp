/*
Name: Gareth Warren
Date: 10/14/21
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Chapter 10 Pointers
Part 1: Using 3 Variables; two pointers, and an int, demonstrate how to use pointers

Part 2: Using WadWas.h class, demonstrate the concept of Deep Copy verses Shallow Copy
by using the classes Copy Constructor, and Destructor methods
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "WadWas.h"

using namespace std;

int main(){
    int integer = 7;
    int *intPtr = &integer;
    int **ptrPtr =  &intPtr;
    
    cout << "\nPart 1: Using three Variables, demonstrate the use of pointers.\n" << endl;
    cout << "integer is a standard integer" << endl;
    cout << "intPtr is a pointer that points to integer" << endl;
    cout << "ptrPtr is a pointer to the pointer intPtr" << endl;
    cout << "Value of integer: " << integer << endl;
    cout << "Address of integer: " << &integer << endl;
    cout << "Value of intPtr: " << intPtr << endl;
    cout << "Address of intPtr: " << &intPtr << endl;
    cout << "Dereference of intPtr: " << *intPtr << endl;
    cout << "Value ptrPtr: " << ptrPtr << endl;
    cout << "Address of ptrPtr: " << &ptrPtr << endl;
    cout << "Dereference of ptrPtr: " << *ptrPtr << endl;
    cout << "Double Dereference of ptrPtr: " << **ptrPtr << endl;

    cout << "\nPart 2: Demonstrate a proper, and improper wrapper class for a dynamic array of 5 elements" << endl;
    WrapArrayDeep deepArray;
    WrapArrayShallow shallowArray;
    WrapArrayDeep deepCopy = WrapArrayDeep(deepArray);
    WrapArrayShallow shallowCopy = WrapArrayShallow(shallowArray);
    
    cout << "\nArrays on Creation:" << endl;
    cout << "Deep: ";
    deepArray.DisplayDeepArray();
    cout << "Deep Copy: ";
    deepCopy.DisplayDeepArray();
    cout << "Shallow: ";
    shallowArray.DisplayShallowArray();
    cout << "Shallow Copy: ";
    shallowCopy.DisplayShallowArray();
    cout << endl;
    
    deepCopy.ChangeValues();
    shallowCopy.ChangeValues();
    
    cout << "After Changing Values in the Arrays: " << endl;
    cout << "Deep: ";
    deepArray.DisplayDeepArray();
    cout << "Deep Copy: ";
    deepCopy.DisplayDeepArray();
    cout << "Shallow: ";
    shallowArray.DisplayShallowArray();
    cout << "Shallow Copy: ";
    shallowCopy.DisplayShallowArray();
    
    system("pause");
    return 0;
}