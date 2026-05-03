#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    struct Time {
        int h, m, s;
    };

    struct Participant {
        string name;
        Time startTime;
        Time finishTime;
    };

    struct Result {
        string name;
        Time duration;
    };

    Participant participants[3] = {
        {"Іванов І.І.", {10, 0, 0}, {10, 45, 30}},
        {"Петров П.П.", {10, 2, 0}, {10, 48, 15}},
        {"Сидоров С.С.", {10, 4, 0}, {10, 49, 50}}
    };
    
    int size = 3;
    Result* raceResults = new Result[size];

    for (int i = 0; i < size; i++) {
        raceResults[i].name = participants[i].name;

        int startSec = participants[i].startTime.h * 3600 + participants[i].startTime.m * 60 + participants[i].startTime.s;
        int finishSec = participants[i].finishTime.h * 3600 + participants[i].finishTime.m * 60 + participants[i].finishTime.s;
        int diff = finishSec - startSec;

        raceResults[i].duration.h = diff / 3600;
        diff %= 3600;
        raceResults[i].duration.m = diff / 60;
        raceResults[i].duration.s = diff;
    }

    for (int i = 0; i < size; i++) {
        cout << raceResults[i].name << " - "
             << setfill('0') << setw(2) << raceResults[i].duration.h << ":"
             << setfill('0') << setw(2) << raceResults[i].duration.m << ":"
             << setfill('0') << setw(2) << raceResults[i].duration.s << "\n";
    }

    delete[] raceResults;
    return 0;
}
