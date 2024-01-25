#include <iostream>
#include <fstream>

using namespace std;

// Funkcija apskaièiuojanti neuþdengtos sienos dalies plotà
int neuzdengtas_plotas(int sienos_plotis, int sienos_aukstis, int plakatai[][4], int N) {
    // Skaièiuojame visà sienos plotà
    int viso_plotas = sienos_plotis * sienos_aukstis;

    // Sumaþiname plotà kiekvieno plakato dydþiu
    for (int i = 0; i < N; ++i) {
        int x1 = plakatai[i][0], y1 = plakatai[i][1], x2 = plakatai[i][2], y2 = plakatai[i][3];
        viso_plotas -= (x2 - x1) * (y2 - y1);
    }

    // Gràþiname likusá neuþdengtà plotà
    return viso_plotas;
}

int main() {
    // Atidarome duomenø failà skaitymui
    ifstream df("duomenys.txt");

    // Atidarome rezultatø failà raðymui
    ofstream rf("rezultatas.txt");

    // Tikriname, ar duomenø failo atidarymas pavyko
    if (!df) {
        cout << "Nepavyko atidaryti duomenu failo." << endl;
        return 1;  // Gràþiname klaidos kodà
    }

    // Skaitykite duomenis ið failo
    int sienos_plotis, sienos_aukstis, N;
    df >> sienos_plotis >> sienos_aukstis >> N;

    // Áraðome plakatø koordinates á masyvà
    int plakatai[N][4];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            df >> plakatai[i][j];
        }
    }

    // Uþdengtas plotas = viso plotas - neuþdengtas plotas
    int rezultatas = neuzdengtas_plotas(sienos_plotis, sienos_aukstis, plakatai, N);

    // Áraðome rezultatà á rezultatø failà
    rf << rezultatas << endl;

    // Uþdarome duomenø ir rezultatø failus
    df.close();
    rf.close();

    return 0;
}

