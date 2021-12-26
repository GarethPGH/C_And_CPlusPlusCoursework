#include <iostream>
#include <string>
#include "Handgun.h"
#include "Gun.h"

using std::endl;
using namespace Guns;
//Constructors
Handgun::Handgun():Gun("Generic Handgun", "Number MM Here"){
    this->grips = "Grips";
    this->sights = "Sights";
    this->laser = false;
};

Handgun::Handgun(string manufacturer, string caliber, string grips, string sights, bool laser):Gun(manufacturer, caliber){
    this->grips = grips;
    this->sights = sights;
    this->laser = laser;
};

//Accessors
string Handgun::GetGrips(){
    return this->grips;
};

string Handgun::GetSights(){
    return this->sights;
};

bool Handgun::GetLaser(){
    return this->laser;
};

//Mutators
void Handgun::SetGrips(string grips){
    this->grips = grips;
};

void Handgun::SetSights(string sights){
    this->sights = sights;
};

void Handgun::SetLaser(bool laser){
    this->laser = laser;
};

//Display function
void Handgun::Display() {
    this->Gun::Display();
    cout << "Grips: " << this->grips << endl;
    cout << "Sights: " << this->sights;
    if (this->laser == true) {
        cout << " with laser" << endl;
    }
    else {
        cout << " without laser" << endl;
    }
}