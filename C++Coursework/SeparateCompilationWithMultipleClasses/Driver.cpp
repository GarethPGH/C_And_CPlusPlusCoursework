/*
Name: Gareth Warren
Date: 9/25/2121
Class: CIT-245 Z01
IDE: Visual Studio 2022 Preview

Chapter 11
5 files: Driver.cpp, f.h, f.cpp, g.h, g.cpp. 
f and g implement nearly identical functions; helloFromF, and helloFromG. 
Driver calls each function from both interface files.
*/

#pragma warning(disable: 4996)
#include "f.h"
#include "g.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(){
    cout << "Use of Multiple Files with Headers:" << endl;
    cout << "helloFromF() from f.cpp, with header file f.h" << endl;
    helloFromF();
    cout << "helloFromG() from g.cpp, with header file g.h" << endl;
    helloFromG();

    system("pause");
    return 0;
}