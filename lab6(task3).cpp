#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    struct Team {
        string teamName;
        string city;
        int points;
    };

    struct City {
        string name;
    };

    Team teams[5] = {
        {"Динамо", "Київ", 15},
        {"Шахтар", "Донецьк", 12},
        {"Сокіл", "Київ", 10},
        {"Чорноморець", "Одеса", 8},
        {"Реал", "Одеса", 5}
    };
    
    int teamCount = 5;
    City* tempCities = new City[teamCount];
    int cityCount = 0;

    for (int i = 0; i < teamCount; i++) {
        bool found = false;
        for (int j = 0; j < cityCount; j++) {
            if (tempCities[j].name == teams[i].city) {
                found = true;
                break;
            }
        }
        if (!found) {
            tempCities[cityCount].name = teams[i].city;
            cityCount++;
        }
    }

    City* finalCities = new City[cityCount];
    for (int i = 0; i < cityCount; i++) {
        finalCities[i] = tempCities[i];
        cout << finalCities[i].name << "\n";
    }

    delete[] tempCities;
    delete[] finalCities;
    return 0;
}
