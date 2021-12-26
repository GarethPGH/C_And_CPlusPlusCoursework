#include <iostream>
#include <string>
#include "Revolver.h"
#include "Handgun.h"

using std::endl;
using namespace Guns;

//Constructors
Revolver::Revolver() :Handgun("Generic Revolver", "Number MM Here", "Grips", "Sights", false){
    this->singleAction = true;
    this->numberOfRounds = 0;
};

Revolver::Revolver(string manufacturer, string caliber, string grips, string sights, bool laser, bool singleAction, int numberOfRounds) :Handgun(manufacturer, caliber, grips, sights, laser){
    this->singleAction = singleAction;
    this->numberOfRounds = numberOfRounds;
};

//Accessors
bool Revolver::GetSingleAction(){
    return this->singleAction;
};

int Revolver::GetNumberOfRounds(){
    return this->numberOfRounds;
};

//Mutators
void Revolver::SetSingleAction(bool singleAction){
    this->singleAction = singleAction;
};

void Revolver::SetNumberOfRounds(int numberOfRounds){
    this->numberOfRounds = numberOfRounds;
};

//Display function
void Revolver::Display() {
    this->Handgun::Display();
    cout << "Number of chambered rounds: " << this->numberOfRounds << endl;
    if (this->singleAction == true) {
        cout << "Type: Single-Action Revolver" << endl;
    }
    else {
        cout << "Type: Dual-Action Revolver" << endl;
    }
}