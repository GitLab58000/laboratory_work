#include <iostream>
#include <clocale>
using namespace std;

double cylinderVolume(double r, double h) {
    return 2 * 3.14159 * r * h;
}

double max2(double x, double y) {
    return (x > y) ? x : y;
}

double max3(double x, double y, double z) {
    return max2(max2(x, y), z);
}

unsigned int reverseDigits(unsigned int n) {
    unsigned int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int choice;
    cout << "1 - Завдання 1 (Циліндр)\n";
    cout << "2 - Завдання 2 (Вираз з max)\n";
    cout << "3 - Завдання 3 (Зворотний порядок цифр)\n";
    cout << "Виберіть завдання: ";
    cin >> choice;

    if (choice == 1) {
        double r, h;
        cout << "Введіть радіус та висоту: ";
        cin >> r >> h;
        cout << cylinderVolume(r, h) << "\n";
    } 
      
    else if (choice == 2) {
        double a, b, c;
        cout << "Введіть a, b, c: ";
        cin >> a >> b >> c;
        double num = max2(a, a + b) + max2(a, b + c);
        double den = 1 + max3(a + b * c, b - c, 25.0);
        cout << num / den << "\n";
    } 
      
    else if (choice == 3) {
        unsigned int num;
        cout << "Введіть натуральне число: ";
        cin >> num;
        cout << reverseDigits(num) << "\n";
    } 
    
    else {
        cout << "Невірний вибір\n";
    }
    return 0;
}
