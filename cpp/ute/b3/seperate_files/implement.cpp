#include <iostream>
#include <string>
#include "header_tst.h"
using namespace std;

Greeting::Greeting(string name) { setName(name); }

void Greeting::setName(string name) { Name = name; }

string Greeting::getName() { return Name; }
    
void Greeting::displayMessage() { 
    cout << "Welcome \n" << getName() << "!" << endl; 
}