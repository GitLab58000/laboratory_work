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

    struct Train {
        string number;
        string destination;
        double distance;
        Time departure;
        Time arrival;
        Time travelTime;
    };

    Train trains[4] = {
        {"101Ш", "Київ", 500, {8, 30}, {15, 0}, {6, 30}},
        {"202Л", "Львів", 600, {5, 0}, {14, 0}, {9, 0}},
        {"303К", "Київ", 450, {9, 15}, {14, 15}, {5, 0}},
        {"404О", "Одеса", 700, {11, 0}, {20, 0}, {9, 0}}
    };

    Train longestTrain = trains[0];
    int maxDuration = longestTrain.travelTime.hours * 60 + longestTrain.travelTime.minutes;

    for (int i = 1; i < 4; i++) {
        int currentDuration = trains[i].travelTime.hours * 60 + trains[i].travelTime.minutes;
        if (currentDuration > maxDuration) {
            maxDuration = currentDuration;
            longestTrain = trains[i];
        }
    }

    cout << "Найтриваліший час у дорозі:\n";
    cout << "Номер: " << longestTrain.number << ", Станція: " << longestTrain.destination << "\n\n";

    cout << "Поїзди до Києва (відправлення з 6:00 до 10:00):\n";
    bool foundKyivTrain = false;

    for (int i = 0; i < 4; i++) {
        int depMinutes = trains[i].departure.hours * 60 + trains[i].departure.minutes;
        
        if (trains[i].destination == "Київ" && depMinutes >= 360 && depMinutes <= 600) {
            foundKyivTrain = true;
            cout << "Номер: " << trains[i].number << "\n"
                 << "Відстань: " << trains[i].distance << " км\n"
                 << "Відправлення: " << setfill('0') << setw(2) << trains[i].departure.hours << ":" 
                 << setfill('0') << setw(2) << trains[i].departure.minutes << "\n"
                 << "Прибуття: " << setfill('0') << setw(2) << trains[i].arrival.hours << ":" 
                 << setfill('0') << setw(2) << trains[i].arrival.minutes << "\n"
                 << "Час у дорозі: " << trains[i].travelTime.hours << " год " 
                 << trains[i].travelTime.minutes << " хв\n\n";
        }
    }

    if (!foundKyivTrain) {
        cout << "Таких поїздів немає.\n";
    }
    return 0;
}
