#include <iostream>

using namespace std;

class Welcome {
    public:
        void displayMessage(string Name) {
            cout << "Welcome to C++ " << Name << "!\n" << endl;
        }
};

int main() {
    Welcome myGreeting;
    string Name;
    getline(cin, Name);
    cout << endl;
    myGreeting.displayMessage(Name);
    // system("pause");

    return 0;
}