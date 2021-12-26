/*Name: Gareth Warren
Date: 11/26/2021
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Chapter 14:
Write a program that calculates the product of a series of integers using a variable-length argument list. 
Test with several calls, each with a different number of arguments.*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

int multiplyVariableNumInts(int numberOfInts, ...){
    int product = 1;
    va_list listOfArgs;
    
    va_start(listOfArgs, numberOfInts);
    for(int integer = 0; integer < numberOfInts; integer++){
        product *= va_arg(listOfArgs, int);
    }
    va_end(listOfArgs);

    return product;
}

int main(){
    int mult2Ints = multiplyVariableNumInts(2, 2,2);
    int mult3Ints = multiplyVariableNumInts(3, 3,2,4);
    int mult4Ints = multiplyVariableNumInts(4, 3,5,6,2);
    int multALotOfInts = multiplyVariableNumInts(22, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23);
    int multALotOfIntsButMakeZero = multiplyVariableNumInts(23, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,0);
    int multOnly3s = multiplyVariableNumInts(5, 3,3,3,3,3);
    
    printf("\nResults of Using Variable Argument Lists\n");
    printf("Multiply 2 Ints: %i\n", mult2Ints);
    printf("Multiply 3 Ints: %i\n", mult3Ints);
    printf("Multiply 4 Ints: %i\n", mult4Ints);
    printf("Multiply A Lot Of Ints: %i\n", multALotOfInts);
    printf("Multiply Ints but Make Zero: %i\n", multALotOfIntsButMakeZero);
    printf("Multiply Only 3s: %i\n", multOnly3s);
 
    system("pause");
    return 0;
}