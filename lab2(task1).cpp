#include <iostream>
#include <string>
using namespace std;

int main() {
    string S = "Mathematic - a queen of the science";
    cout << "Вхідні дані: S = \"" << S << "\"\n";
    cout << "Вихідні дані: A symbols: ";

    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == ' ') {
            string symvoly = "";
            size_t j = i + 1;
            int count = 0;
            
            while (j < S.length() && S[j] != ' ' && count < 2) {
                symvoly += S[j];
                j++;
                count++; }
            if (!symvoly.empty()) {
                cout << symvoly << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
