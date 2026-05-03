#include <iostream>
#include <string>
using namespace std;

int main() {
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);

    string vowels = "aeiouyAEIOUY";
    int count1 = 0;
    int count2 = 0;
    
    for (char c : S1) {
        if (vowels.find(c) != string::npos) {
            count1++;
        }
    }

    for (char c : S2) {
        if (vowels.find(c) != string::npos) {
            count2++;
        }
    }

    cout << count1 << endl;
    cout << count2 << endl;
    return 0;
}
