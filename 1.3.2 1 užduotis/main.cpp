//�i programa nuskaito didesn� arba betkur� skai�i� i� i�vest�, j� �ra�o � rezultat� fail� ir i�veda � ekran�
//prijungiame bibliotekas
#include <iostream> //skirta cin ir cout i�vestim naudoti
#include <fstream> //skirta nuskaityti ir �ra�yti duomenis i� duomen� � rezultat� fail�

using namespace std; //kad nereikt� ra�yti std pries cout cin endl fl df

const char failas[] = "Failas.txt"; // Nurodomas failas, � kur� bus �ra�omas did�iausias skai�ius
//Funkcij� prototipai
int isvesti(); // Funkcijos isvesti prototipas

int skaiciai() // Funkcija, kuri pra�o �vesti 2 skai�ius ir gr��ina didesn�
{
    setlocale(LC_ALL, "Lithuanian"); // Naudojama lietuvi� kalba
    int pirmas, antras; // kintamieji pirmas skai�ius ir antras skai�ius
    //pra�ome �vesti duomenis
    cout << "�veskite du skai�ius:" ;
    cin >> pirmas >> antras;
    //tikrinamas kuris skai�ius didesnis
    if (pirmas >= antras) {
        return pirmas;
    } else {
        return antras;
    }
}

int main() // Pagrindin� funkcija, kuri �ra�o gaut� didesn� skai�i� � fail� ir i�kvie�ia funkcij� "isvesti"
{
    ofstream fl(failas); // Sukuriamas failo srautas ra�ymui
    fl << skaiciai(); // �ra�omas did�iausias skai�ius � fail�
    fl.close(); // U�daromas failo srautas
    isvesti(); // I�kvie�iama funkcija isvesti
    return 0;
}

int isvesti() // Funkcija isvesti, kuri nuskaito i� failo skai�i� ir i�veda � konsol�
{
    int skaicius;
    ifstream fl(failas); // Sukuriamas failo srautas skaitymui
    fl >> skaicius; // Nuskaitomas skai�ius i� failo
    cout << skaicius; // I�vedamas skai�ius � konsol�
}
