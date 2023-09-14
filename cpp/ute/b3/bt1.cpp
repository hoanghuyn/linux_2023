#include <iostream>
using namespace std;

class data {
    public:
        
        data() {                // constructor
            grade1 = -1;
            grade2 = -1;
        }
    
        void enterData() {      // member function      
            cout << "Enter grade 1: ";
            cin >> grade1;
            cout << "Enter grade 2: ";
            cin >> grade2;
        }
        
        void display() {        // member function
            cout << "Greater grade: " << ((grade1 > grade2) ? grade1 : grade2) << endl;
        }

    private:            
        int grade1;             // data member
        int grade2;             // data member
};

int main()
{
    data myData;
    myData.enterData();
    myData.display();
    // system("pause");

    return 0;
}