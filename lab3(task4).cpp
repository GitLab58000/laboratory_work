#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cout << "S: ";
    getline(cin, S);

    int balance = 0;
    bool isBalanced = true;

    for (char c : S) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
        }
        
        if (balance < 0) {
            isBalanced = false;
            break;
        }
    }
    if (balance != 0) {
        isBalanced = false;
    }
    if (isBalanced) {
        cout << "Дужки збалансовані" << endl;
    } else {
        cout << "Дужки не збалансовані" << endl;
    }
    return 0;
}
