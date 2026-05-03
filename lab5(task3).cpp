#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    struct Address {
        string street;
        string building;
        string apartment;
    };

    struct Voter {
        string fullName;
        Address address;
        string passport;
        int birthYear;
        bool hasVoted;
    };

    struct PollingStation {
        Voter voters[100];
        int totalVoters;

        double percentVotedUnder35(int currentYear) {
            int youngTotal = 0;
            int youngVoted = 0;

            for (int i = 0; i < totalVoters; i++) {
                if ((currentYear - voters[i].birthYear) < 35) {
                    youngTotal++;
                    if (voters[i].hasVoted) {
                        youngVoted++;
                    }
                }
            }

            if (youngTotal == 0) return 0.0;
            return (double)youngVoted / youngTotal * 100.0;
        }

        int countVotedOnZehelya() {
            int count = 0;
            for (int i = 0; i < totalVoters; i++) {
                if (voters[i].address.street == "Зегеля" && voters[i].hasVoted) {
                    count++;
                }
            }
            return count;
        }
    };

    PollingStation station;
    station.totalVoters = 4;

    station.voters[0] = {"Іванов І.І.", {"Зегеля", "10", "5"}, "АА123456", 1995, true};
    station.voters[1] = {"Петров П.П.", {"Шевченка", "5", "1"}, "ВВ654321", 1980, false};
    station.voters[2] = {"Сидоров С.С.", {"Зегеля", "12", "10"}, "СС112233", 2000, true};
    station.voters[3] = {"Коваленко К.К.", {"Зегеля", "8", "2"}, "КК998877", 1992, false};

    int currentYear = 2024;

    cout << "Відсоток виборців молодше 35 років, які проголосували: " 
         << station.percentVotedUnder35(currentYear) << "%\n";

    cout << "Кількість виборців з вулиці Зегеля, які проголосували: " 
         << station.countVotedOnZehelya() << "\n";
    return 0;
}
