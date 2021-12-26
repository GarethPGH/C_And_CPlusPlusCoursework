/*Name: Gareth Warren
* Date: 9 / 3 / 2021
* Class: CIT 245 Z01
* 
* This program calculates the Bouyant Force of a sphere after calculating it's volume.
* It then compares the Bouyant Force to the Weight of the sphere.
* If the sphere's weight is greater than the bouyant force, the sphere sinks, otherwise it floats.
* The user is allowed to test however many spheres they wish.
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
#include <iostream>

using namespace std;


//Calculates the Volume of a Sphere given its radius
double CalculateSphereVolume(double radius) {
	double volume = 0.0;
	double radiusCubed = radius * radius * radius;
	const double PI = 3.141592;
	
	volume = (4.0 / 3.0) * PI * radiusCubed;

	return volume;
}

//Calculates Bouyant Force given a volume of an object
double CalculateBouyantForce(double volume) {
	const double WATER_WEIGHT = 62.4;
	return volume * WATER_WEIGHT;
}

int main() {
	//Inputs
	double sphereRadius = 0.0;
	double sphereWeight = 0.0;
	string selection = "";
	
	//Calculated Inputs
	double sphereVolume = 0.0;
	double bouyantForce = 0.0;

	//Loop Control
	bool goAgain = false;
	
	do {
		cout << "Enter the radius of your sphere\n";
		cin >> sphereRadius;
		cout << "Enter the weight of your sphere\n";
		cin >> sphereWeight;

		sphereVolume = CalculateSphereVolume(sphereRadius);
		bouyantForce = CalculateBouyantForce(sphereVolume);

		cout << "Radius of Sphere: " << sphereRadius << endl;
		cout << "Weight of Sphere: " << sphereWeight << " lbs\n";
		cout << "Bouyant Force: " << bouyantForce << endl;

		if (sphereWeight > bouyantForce) {
			cout << "The sphere sinks\n";
		}
		else {
			cout << "Egads! The sphere floats!\n";
		}

		cout << "Do you want to test another sphere?\n";
		cin >> selection;

		if (selection == "yes" || selection == "Yes" || selection == "YES" || selection == "Y" || selection == "y") {
			goAgain = true;
		}
		else {
			cout << "Exiting Program\n";
			goAgain = false;
		}

	} while (goAgain);

	system("pause");
	return 1;
}