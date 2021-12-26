#include <string>
#include <ostream>
using std::string;
using std::cout;

#ifndef GUN_H
#define GUN_H

//Gun is an abstract class 
//it can be inherited from to create multiple types of guns 
//It does not make sense to be instantiated on its own

namespace Guns {
    class Gun {
    
    protected:
        string manufacturer;

    public:
        Gun();
        Gun(string manufacturer, string caliber);

        string GetManufacturer();
        string GetCaliber();

        void SetManufacturer(string manufacturer);
        void SetCaliber(string caliber);

        string caliber;

        virtual void Print()=0;
    };
}
#endif 