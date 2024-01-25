#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char duomenu_failas[] = "pirkiniai.txt";
const char rezultatu_failas[] = "islaidos.txt";

int main() {

    int n, m;
    double suma = 0.0; // Kintamasis, kuriame saugoma bendra suma.

    setlocale(LC_ALL, "Lithuanian"); // Nustatoma lietuviø kalba, kad bûtø naudojamos lietuviðkos raidës.

    ifstream df(duomenu_failas); // Atidaromas duomenø failas "pirkiniai.txt".

    if (!df) // Patikrinama, ar failo atidarymas buvo sëkmingas.
    {
        cout << "Failas neatidarytas." << endl; // Jei failas neatidarytas, iðvedamas praneðimas ir programa baigia darbà.
        return -1;
    }
    else
    {
        df >> n >> m; // Nuskaitomi duomenys apie parduotuviø ir prekiø skaièius ið duomenø failo.

        ofstream rf(rezultatu_failas); // Atidaromas rezultatø failas "islaidos.txt".

        for (int i = 0; i < n; i++) {
            double suma_pard = 0.0; // Kintamasis, kuriame saugoma kiekvienos parduotuvës suma.

            for (int j = 0; j < m; j++) {
                double kaina;
                df >> kaina; // Nuskaitoma prekës kaina ið duomenø failo.
                suma_pard += kaina; // Atnaujinama parduotuvës suma.
                suma += kaina; // Atnaujinama bendra suma.
            }

            rf << "Parduotuvë " << (i + 1) << ": " << fixed << setprecision(2) << suma_pard << endl; // Rezultatø faile iðvedama parduotuvës suma su nurodytu tikslumu.

        }

        rf << "Viso iðleista: " << fixed << setprecision(2) << suma << endl; // Rezultatø faile iðvedama bendra suma su nurodytu tikslumu.

        df.close(); // Uþdaromas duomenø failas.
        rf.close(); // Uþdaromas rezultatø failas.

        return 0; // Programa baigia darbà sëkmingai.
    }
}

