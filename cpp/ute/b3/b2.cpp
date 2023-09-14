#include <iostream>

using namespace std;

class Greeting {
    public:
        void setName(string name) { Name = name; }
        string getName() { return Name; }
        void displayMessage() {
            cout << "Welcome to C++ " << getName() << "!\n" << endl;
        }
    private:
        string Name;
};

int main()
{
    string myName;
    Greeting nameOfCourse;
    cout << "Initial course name is C++ " << myName.getName() << endl;
    cout << "\nPlease enter your name:" << endl;
    getline(cin, myName);
    myGreeting.displayMessage(Name);
    // system("pause");

    return 0;
}