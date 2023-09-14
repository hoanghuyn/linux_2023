#include <iostream>
#include <string>
using namespace std;

void enter_array(int *a, int n) {
    cout << "Enter an array of " << n << " integers: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter a[" << i << "]: ";
        cin >> a[i];
    }
}

void enter_array(float *a, int n) {
    cout << "Enter an array of " << n << " floats: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter a[" << i << "]: ";
        cin >> a[i];
    }
}

int find_max(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

float find_max(float *a, int n) {
    float max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

int main() {
    int arr_int[3] = {2, 5, 3};
    float arr_float[3] = {2.5, 5.3, 3.2};

    // enter_array(arr_int, 5);
    // enter_array(arr_float, 5);

    cout << "Max of arr_int: " << find_max(arr_int, 3) << endl;
    cout << "Max of arr_float: " << find_max(arr_float, 3) << endl;

    return 0;
}