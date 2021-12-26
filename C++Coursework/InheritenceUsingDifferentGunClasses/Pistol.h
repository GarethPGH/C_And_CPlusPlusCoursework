#include <string>
#include "Handgun.h"
using std::string;

#ifndef PISTOL_H
#define PISTOL_H

namespace Guns {
    class Pistol :public Handgun {
    private:
        bool semiauto;

    public:
        Pistol();
        Pistol(string manufacturer, string caliber, string grips, string sights, bool laser, bool semiauto);
        
        bool GetSemiAuto();

        void SetSemiAuto(bool semiauto);

        void Display();
    };
}

#endif