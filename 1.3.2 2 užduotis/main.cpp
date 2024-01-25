//Programa praðo ávesti savo paskutiná paþymá ir iðveda ar paþymys yra teigiamas ar neigiamas
#include <iostream>   // Átraukiame ávedimo/iðvedimo bibliotekà cout cin
#include <fstream>    // Átraukiame failø ávedimo/iðvedimo bibliotekà

using namespace std;  // Nereiktø priraðyti std prie cout cin endl fl bool

const char failas[] = "Failas.txt";  // Sukuriame konstantà, nurodanèià failo pavadinimà
//tikriname ar paþymys yra teigiamas ar neigiamas
bool ar_pazymys_teigiams(double pazymys) {
    return pazymys >= 4.0;  // Gràþiname 'true', jei paþymys yra didesnis arba lygus 4.0, kitaip 'false'
}
//funkcija iðvesti kad paþymys yra teigiamas arba neigiamas
void isvesti_informacija(bool rezultatas) {
    if (rezultatas) {
        cout << "Jûsø paþymys yra teigiamas." << endl;  // Iðvedame praneðimà, jei paþymys yra teigiamas
    } else {
        cout << "Jûsø paþymys yra neigiamas." << endl;  // Iðvedame praneðimà, jei paþymys yra neigiamas
    }
}

int main() { // pagrindinë funkcija
    double pazymys;  // Deklaruojame kintamàjá, skirtà saugoti vartotojo ávestà paþymá

    // Leidþiame vartotojui suvesti paþymá
    cout << "Áveskite savo paskutiná paþymá: ";
    cin >> pazymys;

    // Tikriname ar paþymys teigiamas ir gràþiname rezultatà
    bool rezultatas = ar_pazymys_teigiams(pazymys);

    // Atidarome rezultatø failà
    ofstream fl(failas);

    // Tikriname rezultatà ir raðome á failà
    isvesti_informacija(rezultatas);
    //tikrinama jei rezultatas yra teigiamas á rezultatø failà iðvedama teigiamas kitaip neigiams
    if (rezultatas) {
        fl << "Teigiamas paþymys";  // Jei paþymys teigiamas, raðome á failà atitinkamà þinutæ
    } else {
        fl << "Neigiamas paþymys";  // Jei paþymys neigiamas, raðome á failà atitinkamà þinutæ
    }

    // Uþdarome rezultatø failà
    fl.close();

    return 0;  // Gràþiname nulá, nes programa baigë darbà be klaidø
}


