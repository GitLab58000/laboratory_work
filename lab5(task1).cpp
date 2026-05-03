#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    struct Address {
        string city;
        string street;
        string building;
    };

    struct AgeCategory {
        int minAge;
        int maxAge;
    };

    struct Toy {
        string name;
        Address manufacturerAddress;
        double price;
        AgeCategory age;
        bool isSport;
    };

    Toy toys[4] = {
        {"М'яч", {"Київ", "Хрещатик", "1"}, 250.0, {3, 12}, true},
        {"Лялька", {"Львів", "Франка", "10"}, 500.0, {2, 5}, false},
        {"Спортивний набір", {"Одеса", "Дерибасівська", "5"}, 400.0, {5, 9}, true},
        {"Велосипед", {"Харків", "Сумська", "20"}, 1500.0, {12, 16}, true}
    };

    double totalCost = 0.0;
    for (int i = 0; i < 4; i++) {
        if (toys[i].isSport && toys[i].age.maxAge <= 10) {
            totalCost += toys[i].price;
        }
    }

    cout << "Сумарна вартість спортивних іграшок для дітей до 10 років: " << totalCost << " грн\n";
    return 0;
}
