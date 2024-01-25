#include <iostream>
#include <fstream>

using namespace std;

// Funkcija skai�iuoja skaitmen� (lenteli�) kiek� kambaryje
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
    ofstream rf("rezultatai.txt"); // Failo pavadinimas, � kur� bus �ra�yti rezultatai
    // Tikriname, ar duomen� failo atidarymas pavyko
    if (!df) {
        cout << "Nepavyko atidaryti failo." << endl;
        return 1; // Gr��iname klaidos kod�
    }
    int n;
    // Nuskaitome duomenis i� failo
    while (df >> n) {
        int pilnas = 0;
        // Skai�iuojame lenteli� skai�i� visiems kabinetams nuo 1 iki n
        for (int i = 1; i <= n; i++) {
            pilnas += lenteliu_sk(i);
        }
        // �ra�ome rezultat� � rezultat� fail�
        rf << pilnas << endl;
    }
    // U�darome duomen� ir rezultat� failus
    df.close();
    rf.close();
    return 0; // Programos pabaiga su s�kme
}
