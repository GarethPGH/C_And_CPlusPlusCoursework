/*
Name: Gareth Warren
Date: 10/27/2121
Class: CIT-245 Z01
IDE: Visual Studio 2022 Community Preview 

Classes of Different Guns to show the concept of Inheritence:
Generic Handgun inherits from Gun
Pistol and Revolver inherit from Handgun, thus also Gun, but are separate from each other

Hard-coded objects display this concept in action
*/


#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

#include "Gun.h"
#include "Handgun.h"
#include "Pistol.h"
#include "Revolver.h"

using namespace Guns;
using std::cout;
using std::endl;

int main(){
    //Testing No-Arg Constructors
    Gun genericGun;
    Handgun genericHandgun;
    Pistol genericPistol;
    Revolver genericRevolver;
    cout << "Four generic guns have been created using the no-arg constructors, showing inherited members:" << endl;
    cout << endl;
    genericGun.Display();
    cout << endl;
    genericHandgun.Display();
    cout << endl;
    genericPistol.Display();
    cout << endl;
    genericRevolver.Display();
    cout << endl;
    
    //Testing Overloaded Constructors in classes Revolver and Pistol
    Pistol glockPistol = Pistol("Glock", "9mm", "Manufacturers Grips", "3 Dot Sights", false, true);

    Revolver smithRevolver = Revolver("Smith & Wesson", "0.357", "Hoague Grips", "Trijicon", true, false, 6);

    cout << "A specific Pistol and a specific Revolver have been created, using the overloaded constructors:" << endl;
    cout << "Their stats are:" << endl;
    cout << endl;

    glockPistol.Display();
    cout << endl;
    smithRevolver.Display();
    cout << endl;

    system("pause");
    return 0;
}