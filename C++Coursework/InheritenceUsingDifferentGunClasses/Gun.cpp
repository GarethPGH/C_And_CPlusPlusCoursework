#include <iostream>
#include <string>
#include "Gun.h"

using namespace Guns;
using std::endl;

//Constructors
Gun::Gun(){
    this->manufacturer = "Generic Gun";
    this->caliber = "Number MM Here";
};

Gun::Gun(string manufacturer, string caliber){
    this->manufacturer = manufacturer;
    this->caliber = caliber;
};

//Accessors
string Gun::GetManufacturer(){
    return this->manufacturer;
};

string Gun::GetCaliber(){
    return this->caliber;
};

//Mutators
void Gun::SetManufacturer(string manufacturer){
    this->manufacturer = manufacturer;
};

void Gun::SetCaliber(string caliber){
    this->caliber = caliber;
};

//Display Function
void Gun::Display() {
    cout << "Manufacturer: " << this->manufacturer << endl;
    cout << "Caliber: " << this->caliber << endl;
}