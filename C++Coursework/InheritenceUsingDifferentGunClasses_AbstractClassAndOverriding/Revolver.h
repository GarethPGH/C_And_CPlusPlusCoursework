#include <string>
#include "Handgun.h"
using std::string;

#ifndef REVOLVER_H
#define REVOLVER_H

namespace Guns {
    class Revolver : public Handgun {
    private:
        bool singleAction;
        int numberOfRounds;

    public:
        Revolver();
        Revolver(string manufacturer, string caliber, string grips, string sights, bool laser, bool singleAction, int numberOfRounds);

        bool GetSingleAction();
        int GetNumberOfRounds();

        void SetSingleAction(bool singleAction);
        void SetNumberOfRounds(int numberOfRounds);

        virtual void Print() override;
    };
}

#endif