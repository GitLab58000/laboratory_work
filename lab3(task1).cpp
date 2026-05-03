#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    getline(cin, S);
    string result = "";
    string vowels = "aeiouyAEIOUY";

    for (char c : S) {
        if (c != ' ') {
            result += c;
            if (vowels.find(c) != string::npos) {
                result += c;
            }
        }
    }

    cout << result << endl;
    return 0;
}
