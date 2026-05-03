#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    struct Movie {
        string title;
        string director;
        string country;
        int year;
        double cost;
        double revenue;
    };

    struct MovieDB {
        Movie movies[100];
        int count;

        void findBestRevenueAfter1991() {
            int maxIdx = -1;
            double maxRev = -1.0;

            for (int i = 0; i < count; i++) {
                if (movies[i].year >= 1991 && movies[i].revenue > maxRev) {
                    maxRev = movies[i].revenue;
                    maxIdx = i;
                }
            }

            if (maxIdx != -1) {
                cout << movies[maxIdx].title << " (" << movies[maxIdx].revenue << ")\n";
            } else {
                cout << "-\n";
            }
        }

        void sortAndPrint() {
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (movies[j].year > movies[j + 1].year) {
                        Movie temp = movies[j];
                        movies[j] = movies[j + 1];
                        movies[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < count; i++) {
                cout << movies[i].year << " | " 
                     << movies[i].title << " | " 
                     << movies[i].director << " | " 
                     << movies[i].country << " | " 
                     << movies[i].cost << " | " 
                     << movies[i].revenue << "\n";
            }
        }
    };

    MovieDB db;
    db.count = 4;
    db.movies[0] = {"Матриця", "Вачовскі", "США", 1999, 63.0, 463.5};
    db.movies[1] = {"Хрещений батько", "Коппола", "США", 1972, 6.0, 245.0};
    db.movies[2] = {"Аватар", "Кемерон", "США", 2009, 237.0, 2847.0};
    db.movies[3] = {"Тіні забутих предків", "Параджанов", "СРСР", 1964, 0.5, 1.2};

    db.findBestRevenueAfter1991();
    db.sortAndPrint();
    return 0;
}
