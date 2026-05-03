#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int F[4][4];

    cout << "Вихідна матриця F(4,4):\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            F[i][j] = rand() % 21 - 10; 
            cout << setw(5) << F[i][j];}
        cout << "\n";
    }
    cout << "\nРезультати:\n";
    cout << "Рядок | Сума від'ємних\n";
    
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            if (F[i][j] < 0) {
                sum += F[i][j];
            }
        }
        cout << setw(5) << i + 1 << " | " << setw(14) << sum << "\n";
    }
    return 0;
}
