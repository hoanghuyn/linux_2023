#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n, m;

    cout << "Enter m: ";
    cin >> m;

    cout << "Enter n: ";
    cin >> n;


    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++) 
        {
            cout << "Enter array[" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    cout << endl << "Array: " << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << "  ";       
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}