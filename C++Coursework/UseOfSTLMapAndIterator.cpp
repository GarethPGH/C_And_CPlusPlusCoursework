/*Name: Gareth Warren
Date: 11/29/2021
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Chapter 19: STL Assignment
Program that demonstrates the use of STL map functions, and associated iterator
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <utility>
#include <map>

using std::pair;
using std::map;
using std::string;
using std::cout;
using std::endl;

void findPerson(map<string, string> personMap, string person){
    if(personMap.find(person) != personMap.end()){
        cout << "The entry " << person << " is in the Map" << endl;
    }else{
        cout << "The entry " << person << " is not in the Map" << endl;
    }
}

int main(){
    cout << endl << "Demonstrating Use of STL Map Functions" << endl;

    map<string, string> ssnMap;
    ssnMap["Bill"] = "123-45-6792";
    ssnMap["Nettuno Vincentius"] = "123-45-6790";
    ssnMap["Isbrand Manoja"] = "123-45-6791";
    ssnMap["Helmfrid Hatshepsut"] = "123-45-6789";
    
    cout << endl << "The Following Individuals Were Added to the Map:" << endl;
    cout << "Nettuno Vincentius, Isbrand Manoja, Helmfrid Hatshepsut, and Bill" << endl;
    cout << endl << "Iterating through the Map to Display their SSNs" << endl;

    map<string, string>::const_iterator person;

    int count = 1;
    for(person = ssnMap.begin(); person != ssnMap.end(); person++){
        cout << count << ": " << person->first << "; " << person->second << endl;
        count++; 
    }

    cout << endl << "Looking for Bill..." << endl;
    findPerson(ssnMap, "Bill");
    cout << endl << "Looking for Blackbeard..." << endl; 
    findPerson(ssnMap, "Blackbeard");
    cout << endl;
 
    system("pause");
    return 0;
}