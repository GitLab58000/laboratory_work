#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    struct Student {
        string lastName;
        string firstName;
        double averageGrade;
        char gender; 
    };

    Student students[4] = {
        {"Коваленко", "Анна", 4.5, 'f'},
        {"Шевченко", "Іван", 3.2, 'm'},
        {"Бойко", "Олена", 4.8, 'f'},
        {"Ткаченко", "Марія", 3.9, 'f'}
    };

    int count = 0;
    cout << "--- Студентки, які отримують стипендію (бал >= 4.0) ---\n";
    
    for (int i = 0; i < 4; i++) {
        if (students[i].gender == 'f' && students[i].averageGrade >= 4.0) {
            count++;
            cout << "Прізвище: " << students[i].lastName << "\n";
            cout << "Ім'я: " << students[i].firstName << "\n";
            cout << "Середній бал: " << students[i].averageGrade << "\n";
            cout << "-----------------------\n";
        }
    }

    cout << "Загальна кількість таких студенток: " << count << endl;
    return 0;
}
