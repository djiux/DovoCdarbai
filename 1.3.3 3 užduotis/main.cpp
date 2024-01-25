#include <iostream>
#include <string>

using namespace std;

// Funkcija, kuri priima vardà, pavardæ ir grupës kodà ir iðveda informacijà
void informacija(string vardas, string pavarde, string grupes_kodas) {
    cout << "Vardas: " << vardas << ", Pavarde: " << pavarde << ", Akademines grupes kodas: " << grupes_kodas << endl;
}

// Funkcija, kuri priima tris skaièius ir iðveda paþymiø vidurká
void vidurkis(double pazymys1, double pazymys2, double pazymys3) {
    double vid = (pazymys1 + pazymys2 + pazymys3) / 3;
    cout << "Pazymiu vidurkis: " << vid << endl;
}

// Apjungianèia funkcija, kuri priima vardà, pavardæ, grupës kodà ir tris skaièius
// Ji iðkvieèia kitas dvi funkcijas su perduotais parametrais
void apjungtiFunkcijas(string vardas, string pavarde, string grupes_kodas, double pazymys1, double pazymys2, double pazymys3) {
    informacija(vardas, pavarde, grupes_kodas);
    vidurkis(pazymys1, pazymys2, pazymys3);
}

int main() {
    // Pirmas kvietimas su konkreèiais duomenimis
    string vardas1 = "Jonas", pavarde1 = "Jonaitis", grupes_kodas1 = "AF3";
    double pazymys11 = 8;
    double pazymys21 = 9;
    double pazymys31 = 7;
    apjungtiFunkcijas(vardas1, pavarde1, grupes_kodas1, pazymys11, pazymys21, pazymys31);

    cout << endl;  // Atskiriamasis tarpas

    // Antras kvietimas su kitais duomenimis
    string vardas2 = "Petras", pavarde2 = "Petraitis", grupes_kodas2 = "BF2";
    double pazymys12 = 7;
    double pazymys22 = 8;
    double pazymys32 = 6;
    apjungtiFunkcijas(vardas2, pavarde2, grupes_kodas2, pazymys12, pazymys22, pazymys32);

    return 0;
}
