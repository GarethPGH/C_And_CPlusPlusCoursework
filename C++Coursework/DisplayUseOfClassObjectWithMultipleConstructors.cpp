/*
Name: Gareth Warren
Date: 9/25/2121
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Class Counter has two constructors to initialize a count variable to zero, or provided integer
A static int counts the number of increments and decrements that have occurred to any created class objects
Increment increases the private field, and static field
Decrement decreases the private field, and increases the static field
Display shows the outcomes of using the class

Sample program initializes two Counter objects using both constructors, and displays the effect of the shared static field
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Counter{
    private:
        int count = 0;
    
    static int totalIncAndDec;
    
    public:
        //Constructors
        Counter(){
            count = 0;
        }
        Counter(int integer){
            count = integer;
        }

        //Methods
        void increment(int integer){
            for(int inc = 0; inc < integer; inc++){
                count++;
                totalIncAndDec++;
            }
        }

        void decrement(int integer){
            for(int dec = 0; dec < integer; dec++){
                count--;
                totalIncAndDec++;
            }
        }

        void display(){
            cout << "Current Count: " << count << endl;
            cout << "Total Number of Increments and Decrements: " << totalIncAndDec << endl << endl;
        }
};

int Counter::totalIncAndDec = 0;

int main(){
  
    Counter count1;
    Counter count2(200);
    cout << "Count 1: " << endl;
    count1.display();
     cout << "Count 2: " << endl;
    count2.display();
    count1.increment(85);
     cout << "Count 1: " << endl;
    count1.display();
    count2.decrement(242);
     cout << "Count 2: " << endl;
    count2.display();

    system("pause");
    return 0;
}