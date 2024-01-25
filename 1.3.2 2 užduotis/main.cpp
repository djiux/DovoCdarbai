//Programa pra�o �vesti savo paskutin� pa�ym� ir i�veda ar pa�ymys yra teigiamas ar neigiamas
#include <iostream>   // �traukiame �vedimo/i�vedimo bibliotek� cout cin
#include <fstream>    // �traukiame fail� �vedimo/i�vedimo bibliotek�

using namespace std;  // Nereikt� prira�yti std prie cout cin endl fl bool

const char failas[] = "Failas.txt";  // Sukuriame konstant�, nurodan�i� failo pavadinim�
//tikriname ar pa�ymys yra teigiamas ar neigiamas
bool ar_pazymys_teigiams(double pazymys) {
    return pazymys >= 4.0;  // Gr��iname 'true', jei pa�ymys yra didesnis arba lygus 4.0, kitaip 'false'
}
//funkcija i�vesti kad pa�ymys yra teigiamas arba neigiamas
void isvesti_informacija(bool rezultatas) {
    if (rezultatas) {
        cout << "J�s� pa�ymys yra teigiamas." << endl;  // I�vedame prane�im�, jei pa�ymys yra teigiamas
    } else {
        cout << "J�s� pa�ymys yra neigiamas." << endl;  // I�vedame prane�im�, jei pa�ymys yra neigiamas
    }
}

int main() { // pagrindin� funkcija
    double pazymys;  // Deklaruojame kintam�j�, skirt� saugoti vartotojo �vest� pa�ym�

    // Leid�iame vartotojui suvesti pa�ym�
    cout << "�veskite savo paskutin� pa�ym�: ";
    cin >> pazymys;

    // Tikriname ar pa�ymys teigiamas ir gr��iname rezultat�
    bool rezultatas = ar_pazymys_teigiams(pazymys);

    // Atidarome rezultat� fail�
    ofstream fl(failas);

    // Tikriname rezultat� ir ra�ome � fail�
    isvesti_informacija(rezultatas);
    //tikrinama jei rezultatas yra teigiamas � rezultat� fail� i�vedama teigiamas kitaip neigiams
    if (rezultatas) {
        fl << "Teigiamas pa�ymys";  // Jei pa�ymys teigiamas, ra�ome � fail� atitinkam� �inut�
    } else {
        fl << "Neigiamas pa�ymys";  // Jei pa�ymys neigiamas, ra�ome � fail� atitinkam� �inut�
    }

    // U�darome rezultat� fail�
    fl.close();

    return 0;  // Gr��iname nul�, nes programa baig� darb� be klaid�
}


