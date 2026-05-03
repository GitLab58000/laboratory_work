#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    const int n = 7;
    int P[n][n];

    cout << "Вихідна матриця P(" << n << "," << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            P[i][j] = rand() % 21 - 10; 
            cout << setw(4) << P[i][j];
        }
        cout << "\n";
    }
    double minAvg = 1e9;
    int minCol = -1;   

    for (int j = 0; j < n; j++) {
        int sum = 0;
        int count = 0;
        
        for (int i = 0; i < n - 1 - j; i++) {
            if (P[i][j] > 0) {
                sum += P[i][j];
                count++;
            }
        }
        
        if (count > 0) {
            double avg = static_cast<double>(sum) / count;
            if (avg < minAvg) {
                minAvg = avg;
                minCol = j;
            }
        }
    }
    if (minCol != -1) {
        cout << "Стовпчик (вище побічної діагоналі) з мінімальним середнім додатних: " << minCol + 1 << endl;
        cout << "Мінімальне середнє арифметичне: " << minAvg << endl;
    } 
    else {
        cout << "Вище побічної діагоналі не знайдено жодного додатного елемента." << endl;
    }

    return 0;
}
