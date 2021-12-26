/*
Name: Gareth Warren
Date: 10/18/2121
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Program that displays temperatures between 0 and 212 degrees fahrenheit converted to celsius
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Convert Fahrenheit temperature to Celsius
double FahrenheitToCelsius(double fahrenheit){
    return ((5.0/9.0) * (fahrenheit - 32.0));
}

int main(){
    double celsius = 0;
    printf("\n%s %19s\n\n","Fahrenheit:","Celsius:");
    for(int temperature = 0;  temperature <=212; temperature++){
        celsius = FahrenheitToCelsius(temperature);
        printf("%3d %+25.3f\n", temperature, celsius);
    }
    system("pause");
    return 0;
}