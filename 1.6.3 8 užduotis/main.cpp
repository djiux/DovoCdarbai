#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_PREKES = 100;

struct Preke {
    string pavadinimas;
    int kiekis;
    double kaina;
};

void skaitytiDuomenis(Preke prekiuSarasas[]) {
    ifstream df("duomenys.txt");

    if (!df) {
        cout << "Klaida atidarant failà duomenys.txt" << endl;
        }

    for (int i = 0; i < MAX_PREKES; ++i) {
        df >> prekiuSarasas[i].pavadinimas >> prekiuSarasas[i].kiekis >> prekiuSarasas[i].kaina;
    }

    df.close();
}

void rasytiRezultatus(double bendrasUzdarbis, double vidutineKaina) {
    ofstream rf("rezultatai.txt");

    rf << fixed << setprecision(2);
    rf << "Bendras uþdarbis: " << bendrasUzdarbis << endl;
    rf << "Vidutinë prekës kaina: " << vidutineKaina << endl;

    rf.close();
}

int main() {
    ofstream rf("rezultatai.txt");
    Preke prekiuSarasas[MAX_PREKES];

    skaitytiDuomenis(prekiuSarasas);

    // Iðveskime pradinæ prekiø informacijà
    rf << setw(15) << "Pavadinimas" << setw(10) << "Kiekis" << setw(15) << "Kaina" << endl;
    for (int i = 0; i < MAX_PREKES; ++i) {
        rf << setw(15) << prekiuSarasas[i].pavadinimas << setw(10) << prekiuSarasas[i].kiekis << setw(15) << prekiuSarasas[i].kaina << endl;
    }

    // Apskaièiuojame bendrà uþdarbá ir vidutinæ prekës kainà
    double bendrasUzdarbis = 0.0;
    for (int i = 0; i < MAX_PREKES; ++i) {
        bendrasUzdarbis += prekiuSarasas[i].kiekis * prekiuSarasas[i].kaina;
    }

    double vidutineKaina = bendrasUzdarbis / MAX_PREKES;

    rasytiRezultatus(bendrasUzdarbis, vidutineKaina);

    return 0;
}
