#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
  
    struct Product {
        string name;
        double price;
        double weight;
        int expMonths; 

        void printIfExpiringSoon() {
            if (expMonths < 3) {
                cout << "Товар: " << name << "\n"
                     << "Ціна: " << price << " грн\n"
                     << "Вага: " << weight << " кг\n"
                     << "Термін придатності: " << expMonths << " міс.\n"
                     << "-----------------------\n";
            }
        }
    };

    int n;
    cout << "Введіть кількість товарів: ";
    cin >> n;

    Product* goods = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nВведіть дані для товару #" << i + 1 << ":\n";
        cout << "Назва: ";
        cin >> goods[i].name;
        cout << "Ціна: ";
        cin >> goods[i].price;
        cout << "Вага: ";
        cin >> goods[i].weight;
        cout << "Термін придатності (в місяцях): ";
        cin >> goods[i].expMonths;
    }

    cout << "\n=== Товари з терміном придатності менше 3 місяців ===\n";
    for (int i = 0; i < n; i++) {
        goods[i].printIfExpiringSoon();
    }

    delete[] goods; 
    return 0;
}
