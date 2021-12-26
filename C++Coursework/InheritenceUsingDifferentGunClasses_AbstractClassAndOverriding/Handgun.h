#include <string>
#include "Gun.h"
using std::string;

#ifndef HANDGUN_H
#define HANDGUN_H

namespace Guns {
    class Handgun :public Gun {
    protected:
        string grips;
        string sights;
        bool laser;

    public:
        Handgun();
        Handgun(string manufacturer, string caliber, string grips, string sights, bool laser);

        string GetGrips();
        string GetSights();
        bool GetLaser();

        void SetGrips(string grips);
        void SetSights(string sights);
        void SetLaser(bool laser);

        virtual void Print() override;
    };
}
#endif