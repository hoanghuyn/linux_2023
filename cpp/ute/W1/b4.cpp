#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    uint16_t n;
    float sum = 0;

    do {    
        cout << "Enter n: ";
        cin >> n;
    } while (n <= 0);

    for(uint16_t i = 1; i <= n; i++)
    {
        sum += (1.0 / i);
    }

    cout << "Sum = " << sum << endl;

    return 0;
}