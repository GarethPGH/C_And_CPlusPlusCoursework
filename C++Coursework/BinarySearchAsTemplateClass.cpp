/*
Name: Gareth Warren
Date: 11/9/21
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Chapter 16
Template of a binary search function
Note: Will not work with strings, due to not wanting to overload the ==, <, and > operators 
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

template<class T> int BinarySearch(T items[], int startIndex, int endIndex, T findMe){
    //Remember Binary Search Requires the array of items passed to it to be in sorted order
    //array of items, and findMe must be compatible with C++ default operators
    int mid = (endIndex + startIndex)/2;
    if(startIndex <= endIndex){
        if(items[mid] == findMe){
            return mid;
        }else if(items[mid] > findMe){
            return BinarySearch(items, startIndex, mid-1, findMe);
        }else if(items[mid] < findMe){
            return BinarySearch(items, mid+1, endIndex, findMe);
        }
    }
    return -1;
}

template<class T> void showResults(int index, T found){
    //Display the results of binary search.
    if(index == -1){
        cout << found << " is not in the array." << endl;
    }else{
        cout << found << " is at index: " << index << endl;
    }
    cout << endl;
}

int main(){
    int intArray[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    char charArray[] = {'a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
    
    int lastIndex = (sizeof(intArray)/sizeof(intArray[0]))-1;
    
    cout << "Contents of Int Array:" << endl;
    
    for(int index = 0; index <= lastIndex; index++){
        cout << intArray[index] << " ";    
    }
    cout << endl << endl; 

    int found = BinarySearch(intArray, 0, lastIndex, 12);
    cout << "Binary Search for 12" << endl;
    showResults(found, 12);
    found = BinarySearch(intArray, 0, lastIndex, 18);
    cout << "Binary Search for 18" << endl;
    showResults(found, 18);
    
    cout << "Contents of Char Array:" << endl;
    for(int index = 0; index <= lastIndex; index++){
        cout << charArray[index] << " ";    
    }
    cout << endl << endl;

    found = BinarySearch(charArray, 0, lastIndex, 'f');
    cout << "Binary Search for 'f'" << endl;
    showResults(found, 'f');
    found = BinarySearch(charArray, 0, lastIndex, 'z');
    cout << "Binary Search for 'z'" << endl;
    showResults(found, 'z');

    system("pause");
    return 0;
}