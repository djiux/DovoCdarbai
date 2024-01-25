#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Funkcija, kuri apskaièiuoja medþiø kieká
int medeliai(int max_x1, int max_y1, int min_x2, int min_y2) {
    return (min_x2 - max_x1) * (min_y2 - max_y1);
}

int main() {
    ifstream df("duomenys.txt"); // Atidaro ávesties failà
    ofstream rf("rezultatai.txt"); // Atidaro rezultatø failà

    // Inicializuojamos kintamøjø reikðmës
    int max_x1 = numeric_limits<int>::min();
    int max_y1 = numeric_limits<int>::min();
    int min_x2 = numeric_limits<int>::max();
    int min_y2 = numeric_limits<int>::max();

    int x1, y1, x2, y2;

    // Skaito duomenis ið ávesties failo
    for (int i = 0; i < 3; ++i) {
        df >> x1 >> y1 >> x2 >> y2;

        // Atnaujina didþiausius x1 ir y1
        if (x1 > max_x1) {
            max_x1 = x1;
        }
        if (y1 > max_y1) {
            max_y1 = y1;
        }

        // Atnaujina maþiausius x2 ir y2
        if (x2 < min_x2) {
            min_x2 = x2;
        }
        if (y2 < min_y2) {
            min_y2 = y2;
        }
    }

    // Skaièiuoja medþiø kieká naudojant funkcijà medeliai
    int kiekis = medeliai(max_x1, max_y1, min_x2, min_y2);

    // Iðveda rezultatus á rezultatø failà
    rf << "Medþiø kiekis: " << kiekis << endl;

    // Uþdaro failus
    df.close();
    rf.close();

    return 0;
}
