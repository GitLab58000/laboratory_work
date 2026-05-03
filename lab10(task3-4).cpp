#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int choice;
    cout << "3 - Завдання 3 (Кількість різних елементів)\n";
    cout << "4 - Завдання 4 (Вставка суми після кратних 5)\n";
    cout << "Виберіть завдання: ";
    cin >> choice;

    if (choice == 3) {
        int n;
        cout << "n = ";
        cin >> n;

        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> *(a + i);
        }

        int distinct_count = 0;
        for (int i = 0; i < n; i++) {
            bool is_unique = true;
            for (int j = 0; j < i; j++) {
                if (*(a + i) == *(a + j)) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                distinct_count++;
            }
        }

        cout << "Кількість різних елементів = " << distinct_count << "\n";

        delete[] a;

    } else if (choice == 4) {
        int n;
        cout << "n = ";
        cin >> n;

        double* a = new double[n];
        for (int i = 0; i < n; i++) {
            cin >> *(a + i);
        }

        double* temp = new double[n * 2];
        int new_n = 0;
        double current_sum = 0;

        for (int i = 0; i < n; i++) {
            *(temp + new_n) = *(a + i);
            new_n++;
            current_sum += *(a + i);

            if (fmod(*(a + i), 5.0) == 0.0) {
                *(temp + new_n) = current_sum;
                new_n++;
            }
        }

        cout << "a[i] = {";
        for (int i = 0; i < new_n; i++) {
            cout << *(temp + i) << (i < new_n - 1 ? ", " : "");
        }
        cout << "}\n";

        delete[] a;
        delete[] temp;

    } else {
        cout << "Невірний вибір\n";
    }
    return 0;
}
