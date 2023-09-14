#include <iostream>
using namespace std;

class data {
    public:
        data() {                // constructor
            x = 10;
            cout << "Square of " << x << " is " << "x^2= " << x*x << endl;
        }

        void enterData() {      // member function      
            cout << "Enter the number you want to square: " << endl;
            cin >> x;
        }
        
        void display() {        // member function
            cout << "x^2 = " << x*x << endl;
        }

    private:            
        int x;                  // data member
};

int main()
{
    data myData;
    myData.enterData();
    myData.display();
    // system("pause");

    return 0;
}