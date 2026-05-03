#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string S;
    cout << "S: ";
    getline(cin, S);

    stringstream ss(S);
    string word;
    string shortest, longest;
    bool first = true;

    while (ss >> word) {
        cout << word << endl;
        
        if (first) {
            shortest = longest = word;
            first = false;
        } else {
            if (word.length() < shortest.length()) {
                shortest = word;
            }
            if (word.length() > longest.length()) {
                longest = word;
            }
        }
    }

    if (!first) {
        cout << "Найменше слово: " << shortest << endl;
        cout << "Найдовше слово: " << longest << endl;
    }
    return 0;
}
