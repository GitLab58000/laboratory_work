#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cout << "S: ";
    getline(cin, S);

    for (char &c : S) {
        c = c + 2;
    }

    cout << "Зашифрований текст: " << S << endl;
    return 0;
}
