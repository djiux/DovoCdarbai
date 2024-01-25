#include <iostream>
#include <fstream>

using namespace std;

// Funkcija apskai�iuojanti neu�dengtos sienos dalies plot�
int neuzdengtas_plotas(int sienos_plotis, int sienos_aukstis, int plakatai[][4], int N) {
    // Skai�iuojame vis� sienos plot�
    int viso_plotas = sienos_plotis * sienos_aukstis;

    // Suma�iname plot� kiekvieno plakato dyd�iu
    for (int i = 0; i < N; ++i) {
        int x1 = plakatai[i][0], y1 = plakatai[i][1], x2 = plakatai[i][2], y2 = plakatai[i][3];
        viso_plotas -= (x2 - x1) * (y2 - y1);
    }

    // Gr��iname likus� neu�dengt� plot�
    return viso_plotas;
}

int main() {
    // Atidarome duomen� fail� skaitymui
    ifstream df("duomenys.txt");

    // Atidarome rezultat� fail� ra�ymui
    ofstream rf("rezultatas.txt");

    // Tikriname, ar duomen� failo atidarymas pavyko
    if (!df) {
        cout << "Nepavyko atidaryti duomenu failo." << endl;
        return 1;  // Gr��iname klaidos kod�
    }

    // Skaitykite duomenis i� failo
    int sienos_plotis, sienos_aukstis, N;
    df >> sienos_plotis >> sienos_aukstis >> N;

    // �ra�ome plakat� koordinates � masyv�
    int plakatai[N][4];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            df >> plakatai[i][j];
        }
    }

    // U�dengtas plotas = viso plotas - neu�dengtas plotas
    int rezultatas = neuzdengtas_plotas(sienos_plotis, sienos_aukstis, plakatai, N);

    // �ra�ome rezultat� � rezultat� fail�
    rf << rezultatas << endl;

    // U�darome duomen� ir rezultat� failus
    df.close();
    rf.close();

    return 0;
}

