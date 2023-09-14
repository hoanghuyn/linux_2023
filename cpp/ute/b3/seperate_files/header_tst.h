#include <string>

using namespace std;

class Greeting {
    public: 
        Greeting(string name);
        void setName(string name);
        string getName();
        void displayMessage();

    private:
        string Name;
};