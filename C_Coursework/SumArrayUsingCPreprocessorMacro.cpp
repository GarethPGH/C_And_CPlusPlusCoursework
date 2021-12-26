/*/*Name: Gareth Warren
Date: 11/15/2021
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Chapter 13:
Define and use a macro SUMARRAY to sum the values of a numeric array.*/

#pragma warning(disable: 4996)
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#define SUMARRAY(array, length, sum){\
    for(int index = 0; index < length; index++)\
    {\
        sum += array[index];\
    }\
}

int main(){
    int arrayOfInt[] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    
    
    printf("Values of Array:\n");
    for(int index = 0; index < 9; index++){
        printf("%i, ", arrayOfInt[index]);
    }
    printf("%i\n", arrayOfInt[9]);

    SUMARRAY(arrayOfInt, 10, sum);

    printf("Values of Array Summed, using SUMARRAY: %i\n", sum);

    system("pause");
    return 0;
}