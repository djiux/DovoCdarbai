//Ði programa nuskaito didesná arba betkurá skaièiø ið iðvestø, já áraðo á rezultatø failà ir iðveda á ekranà
//prijungiame bibliotekas
#include <iostream> //skirta cin ir cout iðvestim naudoti
#include <fstream> //skirta nuskaityti ir áraðyti duomenis ið duomenø á rezultatø failà

using namespace std; //kad nereiktø raðyti std pries cout cin endl fl df

const char failas[] = "Failas.txt"; // Nurodomas failas, á kurá bus áraðomas didþiausias skaièius
//Funkcijø prototipai
int isvesti(); // Funkcijos isvesti prototipas

int skaiciai() // Funkcija, kuri praðo ávesti 2 skaièius ir gràþina didesná
{
    setlocale(LC_ALL, "Lithuanian"); // Naudojama lietuviø kalba
    int pirmas, antras; // kintamieji pirmas skaièius ir antras skaièius
    //praðome ávesti duomenis
    cout << "Áveskite du skaièius:" ;
    cin >> pirmas >> antras;
    //tikrinamas kuris skaièius didesnis
    if (pirmas >= antras) {
        return pirmas;
    } else {
        return antras;
    }
}

int main() // Pagrindinë funkcija, kuri áraðo gautà didesná skaièiø á failà ir iðkvieèia funkcijà "isvesti"
{
    ofstream fl(failas); // Sukuriamas failo srautas raðymui
    fl << skaiciai(); // Áraðomas didþiausias skaièius á failà
    fl.close(); // Uþdaromas failo srautas
    isvesti(); // Iðkvieèiama funkcija isvesti
    return 0;
}

int isvesti() // Funkcija isvesti, kuri nuskaito ið failo skaièiø ir iðveda á konsolæ
{
    int skaicius;
    ifstream fl(failas); // Sukuriamas failo srautas skaitymui
    fl >> skaicius; // Nuskaitomas skaièius ið failo
    cout << skaicius; // Iðvedamas skaièius á konsolæ
}
