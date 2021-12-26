/*
Name: Gareth Warren
Date: 9/24/21
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Program that applies the Sieve Of Eratosthenes. 
Prime Numbers are Revealed by marking off all multiples, starting with 2.
Remaining numbers that are not multiples of other numbers are Prime Numbers, 
and are assumed, only divisible by itself and 1
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <malloc.h>

//Find the Amount of Primes in a Given Number using a bool Array, of length equal to that Number
//Mark all Multiples False, leaving only Prime Numbers
//Index of 0 is not included because 1 is not a Prime Number.
int SieveOfEratosthenes(bool *markedNumbers, const int size){
    int multipleToMark = 0;
    int numberOfPrimes = 0;

    for(int index = 1; index < size; index++){
            
        if(markedNumbers[index] == true){
            numberOfPrimes++;
            multipleToMark = index + 1;
            
            for(int index2 = (index + multipleToMark); index2 < size; index2 += multipleToMark){
                if(markedNumbers[index2] == true){
                    markedNumbers[index2] = false;
                }
            }
        }
    }
    return numberOfPrimes;
}

//Given a bool Array, where True Values are Primes
//Output Prime Numbers by printing the index of each true value plus 1
void PrintPrimes(bool markedNumbers[], const int size){
    int counter = 0;
    for(int index = 0; index < size; index++){
        if(markedNumbers[index] == true){
            counter++;
            if(counter == 10){
                printf("%5d\n", index + 1);
                counter = 0;
            }else{
                printf("%5d, ", index + 1);
            }
        }
    }
}

int main(){
    int number = 0;
    int numberOfPrimes = 0;
    
    printf("Enter the upper limit find prime numbers:");
   
    if(scanf("%d", &number)){
        printf("\n");
        bool* testForPrimes = (bool *)malloc(number);
        testForPrimes[0] = false;
        for(int index = 1; index < number; index ++){
            testForPrimes[index] = true;
        }
        
        numberOfPrimes = SieveOfEratosthenes(testForPrimes, number);
        printf("The List Of Primes Between 1, and %d\n\n", number);
        PrintPrimes(testForPrimes, number);

        printf("\n\nNumber of Primes: %d\n\n", numberOfPrimes);
        
        free(testForPrimes);
    }else{
        printf("This is the wrong kind of input, exiting program\n");
        exit(1);
    };

    system("pause");
    return 0;
}