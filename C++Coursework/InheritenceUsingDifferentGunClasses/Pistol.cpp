#include <iostream>
#include <string>
#include "Pistol.h"
#include "Handgun.h"

using std::endl;
using namespace Guns;

//Constructors
Pistol::Pistol() :Handgun("Generic Pistol", "Number MM Here", "Grips", "Sights", false) {
    this->semiauto = true;
};

Pistol::Pistol(string manufacturer, string caliber, string grips, string sights, bool laser, bool semiauto) :Handgun(manufacturer, caliber, grips, sights, laser) {
    this->semiauto = semiauto;
};

//Accessor
bool Pistol::GetSemiAuto(){
    return this->semiauto;
};

//Mutators
void Pistol::SetSemiAuto(bool semiauto){
    this->semiauto = semiauto;
};

//Display Function
void Pistol::Display() {
    this->Handgun::Display();
    if (this->semiauto == true) {
        cout << "Type: Semi-Automatic Pistol" << endl;
    }
    else {
        cout << "Type: Automatic Pistol" << endl;
    }
}