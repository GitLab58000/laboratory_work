#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "--- Завдання 4.3 ---\n";
    float zero = 0.0, pi = 3.141593, Euler = 2.718282;
    float *ptr = &Euler;

    cout << *(ptr + 1) << "\n";
    cout << *(ptr + 2) << "\n";


    cout << "\n--- Завдання 4.4 ---\n";
    int n;
    cout << "n = ";
    cin >> n;
    
    int* arr4 = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr4 + i);
    }

    int maxAbs = -1;
    for (int i = 0; i < n; i++) {
        if (abs(*(arr4 + i)) > maxAbs) {
            maxAbs = abs(*(arr4 + i));
        }
    }

    for (int i = 0; i < n; i++) {
        cout << *(arr4 + i) << " ";
    }
    
    cout << "\nНомери: ";
    for (int i = 0; i < n; i++) {
        if (abs(*(arr4 + i)) == maxAbs) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    delete[] arr4;


    cout << "\n--- Завдання 4.5 ---\n";
    int m;
    cout << "n = ";
    cin >> m;
    
    double* arr5 = new double[m];
    for (int i = 0; i < m; i++) {
        cin >> *(arr5 + i);
    }

    cout << "Адреси: ";
    for (int i = 0; i < m; i++) {
        cout << (arr5 + i) << (i < m - 1 ? ", " : "");
    }
    cout << ".\n";

    double maxNeg = 1.0; 
    bool foundNeg = false;

    for (int i = 0; i < m; i++) {
        if (*(arr5 + i) < 0) {
            if (!foundNeg || *(arr5 + i) > maxNeg) {
                maxNeg = *(arr5 + i);
                foundNeg = true;
            }
        }
    }

    if (foundNeg) {
        cout << "Max = " << maxNeg << "\n";
    }

    delete[] arr5;

    return 0;
}
