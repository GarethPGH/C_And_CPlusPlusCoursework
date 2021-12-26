#include <string>
#include <ostream>
using std::string;
using std::cout;

#ifndef GUN_H
#define GUN_H

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
        void Display();
    };
}
#endif 