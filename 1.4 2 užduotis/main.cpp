#include <iostream>
#include <fstream>

using namespace std;

// Funkcija skaièiuoja skaitmenø (lenteliø) kieká kambaryje
int lenteliu_sk(int kamb_sk) {
    int skaitmuo = 0;
    while (kamb_sk != 0) {
        kamb_sk /= 10;
        skaitmuo++;
    }
    return skaitmuo;
}
int main() {
    ifstream df("duomenys.txt"); // Failo pavadinimas, kuriame saugomi duomenys
    ofstream rf("rezultatai.txt"); // Failo pavadinimas, á kurá bus áraðyti rezultatai
    // Tikriname, ar duomenø failo atidarymas pavyko
    if (!df) {
        cout << "Nepavyko atidaryti failo." << endl;
        return 1; // Gràþiname klaidos kodà
    }
    int n;
    // Nuskaitome duomenis ið failo
    while (df >> n) {
        int pilnas = 0;
        // Skaièiuojame lenteliø skaièiø visiems kabinetams nuo 1 iki n
        for (int i = 1; i <= n; i++) {
            pilnas += lenteliu_sk(i);
        }
        // Áraðome rezultatà á rezultatø failà
        rf << pilnas << endl;
    }
    // Uþdarome duomenø ir rezultatø failus
    df.close();
    rf.close();
    return 0; // Programos pabaiga su sëkme
}
