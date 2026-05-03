#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
int main() {
    string S = "Mathematic - a queen of the science";
    cout << "Вхідні дані: S = \"" << S << "\"\n";

    stringstream ss(S);
    string word;
    size_t minLen = 1000; 
    size_t maxLen = 0;    

    while (ss >> word) {
        int len = 0;
        
        for (char c : word) {
            if (isalpha(c)) {
                len++;
            }
        }
        if (len > 0) {
            if (len < minLen) minLen = len;
            if (len > maxLen) maxLen = len;
        }}
    cout << "Вихідні дані: " << minLen << ", " << maxLen << endl;
    return 0;
}
