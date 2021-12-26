/*
Name: Gareth Warren
Date: 11/2/2021
Class: CIT-245 Z01
IDE: Visual Studio 2022 Community Preview

Classes of Different Guns:
Generic Handgun inherits from abstract class Gun
Pistol and Revolver inherit from Handgun

Shows the use of virtual functions and overriding  
using the Print() method for each class

Displays the contents of a gunCabinet containing multiple guns

Some values have been changed to make sure the program works as intended
and may not actually reflect the stats of real guns
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

int main() {
	Pistol glock = Pistol{ "Glock", ".40", "Synthetic Grips", "3 dot sights", false, true };
	Pistol hellcat = Pistol{ "Springfield", "9mm", "Textured Grips", "Tritium Night Sights", true, true };
	Pistol deagle = Pistol{ "Magnum Research", ".44","Synthetic Rubber", "Front Sights", false, false };
	Revolver smith = Revolver{ "Smith & Wesson", "0.357", "Hoague Grips", "Trijicon", true, false, 6 };
	Revolver python = Revolver{ "Colt", ".357"," Walnut Target", "Rear Sights", false, true, 6 };
	
	Handgun* gunCabinet[] = { &glock, &hellcat, &deagle, &smith, &python};

	int length = sizeof(gunCabinet) / sizeof(gunCabinet[0]);

	cout << "Gun Cabinet Contents:\n" << endl;
	int count = 1;

	for (int index = 0; index < length; index++) {
		cout << "Gun " << count << ":" << endl;
		gunCabinet[index]->Print();
		cout << endl;
		count++;
	}

	system("pause");
	return 0;
}