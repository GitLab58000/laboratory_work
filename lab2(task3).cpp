#include <iostream>
#include <string>
using namespace std;

int main() {
    string S = "Programming and computing";
    cout << "Вхідні дані: S = \"" << S << "\"\n";
    
    size_t firstSpace = S.find(' ');
    int Pos = (firstSpace != string::npos) ? firstSpace + 1 : 0;
    size_t lastSpace = S.rfind(' ');
    string lastWord = "";
    
    if (lastSpace != string::npos) {
        lastWord = S.substr(lastSpace + 1); 
    }
     
    else {
        lastWord = S;
    }
    
    cout << "Вихідні дані: Position of \" \" = " << Pos << ", \"" << lastWord << "\"" << endl;
    return 0;
}
