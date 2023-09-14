#include <iostream>

using namespace std;

int main()
{
    float a, b;

    cout << "Enter the first float number: ";
    cin >> a;

    cout << "Enter the second float number: ";
    cin >> b;

    float tong = a + b;
    float hieu = a - b;
    float tich = a * b;
    float thuong = a / b;

    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout << "Thuong: " << thuong << endl;

    return 0;
}