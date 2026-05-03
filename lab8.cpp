#include <iostream>
#include <clocale>
using namespace std;

int SumRange(int A, int B) {
    if (A >= B) return 0;
    int sum = 0;
    for (int i = A; i <= B; i++) {
        sum += i;
    }
    return sum;
}

void printDaysInMonth(int m) {
    switch(m) {
        case 1: cout << "У січні 31 день\n"; break;
        case 2: cout << "У лютому 28 днів\n"; break;
        case 3: cout << "У березні 31 день\n"; break;
        case 4: cout << "У квітні 30 днів\n"; break;
        case 5: cout << "У травні 31 день\n"; break;
        case 6: cout << "У червні 30 днів\n"; break;
        case 7: cout << "У липні 31 день\n"; break;
        case 8: cout << "У серпні 31 день\n"; break;
        case 9: cout << "У вересні 30 днів\n"; break;
        case 10: cout << "У жовтні 31 день\n"; break;
        case 11: cout << "У листопаді 30 днів\n"; break;
        case 12: cout << "У грудні 31 день\n"; break;
        default: cout << "Невірний номер місяця\n"; break;
    }
}

double Areal(int n, double a, double b, double h) {
    switch (n) {
        case 1: return 0.5 * a * h;
        case 2: return a * b;
        case 3: return 0.5 * (a + b) * h;
        default: return 0.0;
    }
}

double sumr(int n) {
    if (n == 0) return 1.0;
    return 1.0 / (1.0 + n) + sumr(n - 1);
}

double geomSum(double b1, double q, int n) {
    if (n == 1) return b1;
    return b1 + q * geomSum(b1, q, n - 1);
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int choice;
    cout << "1 - Завдання 1 (SumRange)\n";
    cout << "2 - Завдання 2 (Дні в місяці)\n";
    cout << "3 - Завдання 3 (Площа фігур)\n";
    cout << "4 - Завдання 4 (Ряд sumr)\n";
    cout << "5 - Завдання 5 (Геометрична прогресія)\n";
    cout << "Виберіть завдання: ";
    cin >> choice;

    if (choice == 1) {
        int A, B;
        cout << "Введіть A та B: ";
        cin >> A >> B;
        cout << "Sum = " << SumRange(A, B) << "\n";
    } 
    else if (choice == 2) {
        int m;
        cout << "Введіть номер місяця (m): ";
        cin >> m;
        printDaysInMonth(m);
    } 
    else if (choice == 3) {
        int n;
        double a, b, h;
        cout << "Введіть фігуру (1-трикутник, 2-прямокутник, 3-трапеція): ";
        cin >> n;
        cout << "Введіть a, b, h: ";
        cin >> a >> b >> h;
        cout << "S = " << Areal(n, a, b, h) << "\n";
    } 
    else if (choice == 4) {
        int n;
        cout << "Введіть n: ";
        cin >> n;
        cout << "s = " << sumr(n) << "\n";
    } 
    else if (choice == 5) {
        int n;
        double q, b1;
        cout << "Введіть n, q, b1: ";
        cin >> n >> q >> b1;
        cout << "s_n = " << geomSum(b1, q, n) << "\n";
    } 
    else {
        cout << "Невірний вибір\n";
    }

    return 0;
}
