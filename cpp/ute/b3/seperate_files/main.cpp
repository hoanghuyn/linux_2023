#include <iostream>
#include <string>
#include "header_tst.h"
using namespace std;

int main()
{
    Greeting hi1("Introduction to C++ programming");
    Greeting hi2("Object Oriented Programming");
    cout << "hi1 created for course: " << hi1.getName() 
    << "\nhi2 created for course: " << hi2.getName() << endl;

    return 0;
}