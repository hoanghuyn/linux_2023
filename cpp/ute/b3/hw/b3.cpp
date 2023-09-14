#include <iostream>
#include <string>
using namespace std;

class manage_student {
    public:
        void enter() {
            cout << "Enter student's name: ";
            getline(cin, Name);
            cout << "Enter student's ID: ";
            cin >> SID;
            cout << "Enter student's midterm score: ";
            cin >> midterm;
            cout << "Enter student's final final: ";
            cin >> final;
            cout << endl;
        }

        void resulting() {
            float average = (midterm + final) / 2;
            if (average >= 5.0) result = "passed";
            else result = "failed";
        }

        void display() {
            cout << "Student's name: " << Name << endl;
            cout << "Student's ID: " << SID << endl;
            cout << "Student's midterm score: " << midterm << endl;
            cout << "Student's final score: " << final << endl;
            resulting();
            cout << "Student's result: " << result << endl;
        }

    private:
        string Name;
        int SID;
        float midterm;
        float final;
        string result;
};

int main() {
    
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    manage_student student[n];

    for (uint i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << endl;
        student[i].enter();
    }

    for (uint i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << endl;
        student[i].display();
    }

    return 0;
}