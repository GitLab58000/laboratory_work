#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    struct Time {
        int hours;
        int minutes;
    };

    struct TVProgram {
        string name;
        string genre;
        Time startTime;
        Time endTime;
    };

    TVProgram schedule[3] = {
        {"Новини", "Інформаційна", {18, 0}, {18, 45}},
        {"Мультики", "Дитяча передача", {19, 0}, {19, 30}},
        {"Кіно", "Художній фільм", {20, 0}, {22, 15}}
    };

    cout << "=== Розклад телепрограм ===\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "Програма: " << schedule[i].name << "\n";
        cout << "Жанр: " << schedule[i].genre << "\n";
        
        cout << "Час: " 
             << setfill('0') << setw(2) << schedule[i].startTime.hours << ":" 
             << setfill('0') << setw(2) << schedule[i].startTime.minutes 
             << " - " 
             << setfill('0') << setw(2) << schedule[i].endTime.hours << ":" 
             << setfill('0') << setw(2) << schedule[i].endTime.minutes << "\n";
        cout << "---------------------------\n";
    }

    return 0;
}
