#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    int T[6][4];
    int zeroCount = 0;

    cout << "Вихідна матриця T(6,4):\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            T[i][j] = rand() % 8 - 2; 
            cout << setw(4) << T[i][j];
            
            if (T[i][j] == 0) {
                zeroCount++;
            }
        }
        cout << "\n";}

    cout << "\nКількість нульових елементів: " << zeroCount << endl;
    return 0;
}
