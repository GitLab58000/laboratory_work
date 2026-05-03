#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string S;
    getline(cin, S);
    int spaces = 0;
    int digits = 0;

    for (char c : S) {
        if (c == ' ') {
            spaces++;
        }
        if (isdigit(c)) {
            digits++;
        }
    }

    cout << spaces << endl;
    cout << digits << endl;
    return 0;
}
