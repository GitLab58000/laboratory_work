#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "--- Завдання 4.1 ---\n";
    
    int a = 10;
    char b = 'X';
    float c = 3.14f;
    double d = 2.718;

    int* ptrA = &a;
    char* ptrB = nullptr;
    float* ptrC; 
    double* ptrD = &d;

    ptrB = &b;

    ptrC = new float;
    *ptrC = 5.55f;

    cout << *ptrA << " " << *ptrB << " " << *ptrC << " " << *ptrD << "\n";

    *ptrA = 100;
    *ptrD = 9.99;

    cout << a << " " << d << "\n";

    cout << &a << " " << ptrA << " " << &ptrA << "\n";
    cout << (void*)&b << " " << (void*)ptrB << " " << &ptrB << "\n";
    cout << ptrC << " " << &ptrC << "\n";
    cout << &d << " " << ptrD << " " << &ptrD << "\n";

    delete ptrC;

    cout << "\n--- Завдання 4.2 ---\n";
    
    char ac = 'f', bc = '2';
    char *pac = &ac, *pbc = &bc;
    long int al = 3, bl = 4;
    long int *pal = &al, *pbl = &bl;

    cout << "\nЗначення і різниця вказівників: ";
    cout << "\npac= " << (void*)pac << "\tpbc= " << (void*)pbc;
    cout << "\t(pac-pbc)= " << (pac - pbc);
    cout << "\npal= " << pal << "\tpbl= " << pbl << "\t(pbl-pal)=" << (pbl - pal);
    
    cout << "\nРізниця числових значень вказівників: ";
    cout << "\n(long long)pac-(long long)pbc= " << (long long)pac - (long long)pbc;
    cout << "\n(long long)pbl-(long long)pal= " << (long long)pbl - (long long)pal << "\n";

    return 0;
}
