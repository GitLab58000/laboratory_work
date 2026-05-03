#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int choice;
    cout << "1 - Завдання 1 (Мінімальний елемент з парними номерами)\n";
    cout << "2 - Завдання 2 (Максимальний за модулем та сума між додатними)\n";
    cout << "Виберіть завдання: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "n = ";
        cin >> n;

        double* a = new double[n];
        for (int i = 0; i < n; i++) {
            cin >> *(a + i);
        }

        double min_val = *(a + 1);
        for (int i = 1; i < n; i += 2) {
            if (*(a + i) < min_val) {
                min_val = *(a + i);
            }
        }

        cout << "min = " << min_val << "\n";

        delete[] a;

    } else if (choice == 2) {
        int n;
        cout << "n = ";
        cin >> n;

        double* a = new double[n];
        for (int i = 0; i < n; i++) {
            cin >> *(a + i);
        }

        double max_abs = fabs(*(a + 0));
        for (int i = 1; i < n; i++) {
            if (fabs(*(a + i)) > max_abs) {
                max_abs = fabs(*(a + i));
            }
        }

        double* p1 = nullptr;
        double* p2 = nullptr;

        for (int i = 0; i < n; i++) {
            if (*(a + i) > 0) {
                if (!p1) {
                    p1 = (a + i);
                } else if (!p2) {
                    p2 = (a + i);
                    break;
                }
            }
        }

        double sum = 0;
        if (p1 && p2) {
            for (double* p = p1 + 1; p < p2; p++) {
                sum += *p;
            }
        }

        cout << "max = " << max_abs << ", sum = " << sum << "\n";

        delete[] a;
    } else {
        cout << "Невірний вибір\n";
    }
    return 0;
}
