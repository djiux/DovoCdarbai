#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char duomenu_failas[] = "pirkiniai.txt";
const char rezultatu_failas[] = "islaidos.txt";

int main() {

    int n, m;
    double suma = 0.0; // Kintamasis, kuriame saugoma bendra suma.

    setlocale(LC_ALL, "Lithuanian"); // Nustatoma lietuvi� kalba, kad b�t� naudojamos lietuvi�kos raid�s.

    ifstream df(duomenu_failas); // Atidaromas duomen� failas "pirkiniai.txt".

    if (!df) // Patikrinama, ar failo atidarymas buvo s�kmingas.
    {
        cout << "Failas neatidarytas." << endl; // Jei failas neatidarytas, i�vedamas prane�imas ir programa baigia darb�.
        return -1;
    }
    else
    {
        df >> n >> m; // Nuskaitomi duomenys apie parduotuvi� ir preki� skai�ius i� duomen� failo.

        ofstream rf(rezultatu_failas); // Atidaromas rezultat� failas "islaidos.txt".

        for (int i = 0; i < n; i++) {
            double suma_pard = 0.0; // Kintamasis, kuriame saugoma kiekvienos parduotuv�s suma.

            for (int j = 0; j < m; j++) {
                double kaina;
                df >> kaina; // Nuskaitoma prek�s kaina i� duomen� failo.
                suma_pard += kaina; // Atnaujinama parduotuv�s suma.
                suma += kaina; // Atnaujinama bendra suma.
            }

            rf << "Parduotuv� " << (i + 1) << ": " << fixed << setprecision(2) << suma_pard << endl; // Rezultat� faile i�vedama parduotuv�s suma su nurodytu tikslumu.

        }

        rf << "Viso i�leista: " << fixed << setprecision(2) << suma << endl; // Rezultat� faile i�vedama bendra suma su nurodytu tikslumu.

        df.close(); // U�daromas duomen� failas.
        rf.close(); // U�daromas rezultat� failas.

        return 0; // Programa baigia darb� s�kmingai.
    }
}

