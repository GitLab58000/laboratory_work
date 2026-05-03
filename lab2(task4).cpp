#include <iostream>
#include <string>
using namespace std;

int main() {
    string S = "Mathematic - a queen    of the       science";
    cout << "Вхідні дані: S = \"" << S << "\"\n";

    string result = "";
    bool Space = false;

    for (char c : S) {
        if (c == ' ') {
            if (!Space) {
                result += c;
                Space = true; 
            }
        } else {
            result += c;
            Space = false; 
        }
    }

    cout << "Вихідні дані: S = \"" << result << "\"" << endl;
    return 0;
}
