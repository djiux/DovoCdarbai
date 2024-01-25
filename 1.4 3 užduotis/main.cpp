#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Funkcija, kuri apskai�iuoja med�i� kiek�
int medeliai(int max_x1, int max_y1, int min_x2, int min_y2) {
    return (min_x2 - max_x1) * (min_y2 - max_y1);
}

int main() {
    ifstream df("duomenys.txt"); // Atidaro �vesties fail�
    ofstream rf("rezultatai.txt"); // Atidaro rezultat� fail�

    // Inicializuojamos kintam�j� reik�m�s
    int max_x1 = numeric_limits<int>::min();
    int max_y1 = numeric_limits<int>::min();
    int min_x2 = numeric_limits<int>::max();
    int min_y2 = numeric_limits<int>::max();

    int x1, y1, x2, y2;

    // Skaito duomenis i� �vesties failo
    for (int i = 0; i < 3; ++i) {
        df >> x1 >> y1 >> x2 >> y2;

        // Atnaujina did�iausius x1 ir y1
        if (x1 > max_x1) {
            max_x1 = x1;
        }
        if (y1 > max_y1) {
            max_y1 = y1;
        }

        // Atnaujina ma�iausius x2 ir y2
        if (x2 < min_x2) {
            min_x2 = x2;
        }
        if (y2 < min_y2) {
            min_y2 = y2;
        }
    }

    // Skai�iuoja med�i� kiek� naudojant funkcij� medeliai
    int kiekis = medeliai(max_x1, max_y1, min_x2, min_y2);

    // I�veda rezultatus � rezultat� fail�
    rf << "Med�i� kiekis: " << kiekis << endl;

    // U�daro failus
    df.close();
    rf.close();

    return 0;
}
