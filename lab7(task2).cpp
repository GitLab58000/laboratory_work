#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

double f(double x, double y) {
    return (x * x + x * y - y * y) / (1 + x + y) + (x - y) / (x * x + y * y + 2);
}

double sideLength(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

char checkParam(int param) {
    if (param == 1) return 'p';
    if (param == -1) return 'n';
    cout << "Помилка\n";
    return '0';
}

double func1(double x) {
    return sqrt(1 + log(x));
}

double func2(double x) {
    return log(x + 1) / (x + 1);
}

double trapRule(double (*func)(double), double a, double b, double eps) {
    int n = 1;
    double h = b - a;
    double I1 = h * (func(a) + func(b)) / 2.0;
    double I2 = 0;
    do {
        n *= 2;
        h /= 2.0;
        double sum = 0;
        for (int i = 1; i < n; i += 2) {
            sum += func(a + i * h);
        }
        I2 = I1 / 2.0 + h * sum;
        if (abs(I2 - I1) < eps) break;
        I1 = I2;
    } 
      while (true);
    return I2;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int choice;
    cout << "1 - Завдання 1 (Обчислення u)\n";
    cout << "2 - Завдання 2 (Периметр трикутника)\n";
    cout << "3 - Завдання 3 (Символи)\n";
    cout << "4 - Завдання 4 (Інтеграли)\n";
    cout << "Виберіть завдання: ";
    cin >> choice;

    if (choice == 1) {
        double a, b;
        cout << "Введіть a, b: ";
        cin >> a >> b;
        cout << f(0.5, a) + f(a + b, a - b) << "\n";
    } 
    
    else if (choice == 2) {
        double x1, y1, x2, y2, x3, y3;
        cout << "Введіть x1, y1, x2, y2, x3, y3: ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double p = sideLength(x1, y1, x2, y2) + sideLength(x2, y2, x3, y3) + sideLength(x3, y3, x1, y1);
        cout << p << "\n";
    } 
    
    else if (choice == 3) {
        int n;
        cout << "Введіть параметр (1 або -1): ";
        cin >> n;
        char result = checkParam(n);
        if (result != '0') cout << result << "\n";
    } 
    
    else if (choice == 4) {
        double eps = 1e-3;
        double res1 = trapRule(func1, 2.2, 3.0, eps);
        double res2 = trapRule(func2, 0.0, 1.0, eps);
        cout << res1 + res2 << "\n";
    } 
    
    else {
        cout << "Невірний вибір\n";
    }
    return 0;
}
