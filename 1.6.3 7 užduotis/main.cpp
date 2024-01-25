//Prijungiame bibliotekas
#include <iostream>  // �vedimo ir i�vedimo operacijoms
#include <fstream>   // Fail� �vedimui ir i�vedimui

// Naudotojui nereikia r�pintis std:: prie� funkcijas ifstream ofstream cout endl df rf
using namespace std;

int main() { //Pagrindin� funkcija
    // Atidaryti duomen� fail� �vedimui ir rezultat� fail� i�vedimui
    ifstream df("duomenys.txt");   // �vesties failas
    ofstream rf("rezultatai.txt"); // Rezultat� failas

    // Patikriname, ar pavyko atidaryti �vesties fail�
    if (!df) {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 1;
    }

    // Turima informacija
    int treniruociuSkaicius;
    df >> treniruociuSkaicius;//Nuskaitome duomenis i� failo

    // Masyvas, kuriame saugosime ta�k� kiek� kiekvienoje treniruot�je
    int taskai[100]; // Pavyzdin�s ribos

    // Nuskaitome duomenis i� failo
    for (int i = 0; i < treniruociuSkaicius; i++) {
        df >> taskai[i];
    }

    // Apskai�iuojame vidutini�kai �metamus ta�kus
    double vidurkis = 0;
    for (int i = 0; i < treniruociuSkaicius; i++) {
        vidurkis += taskai[i];
    }
    vidurkis /= treniruociuSkaicius;

    // I�vedame pradinius duomenis � rezultat� fail�
    rf << "Krep�ininko treniruo�i� ta�k� kiekis: ";
    for (int i = 0; i < treniruociuSkaicius; i++) {
        rf << taskai[i] << " ";
    }
    rf << endl;

    // I�vedame gautus atsakymus � rezultat� fail�
    rf << "Krep�ininko vidutini�kai �meta ta�k� per treniruot�: " << vidurkis << endl;

    // Turime komandos vidurk� (galim� i� duomen� failo arba �vesti ranka)
    int komandosVidurkis;
    df >> komandosVidurkis;

    rf << "Komandos vidurkis: " << komandosVidurkis << endl;

    // Palyginimas su komandos vidurkiu ir i�vedimas � rezultat� fail�
    if (vidurkis > komandosVidurkis) {
        rf << "Krep�ininkui sekasi geriau nei komandai." << endl;
    } else if (vidurkis < komandosVidurkis) {
        rf << "Krep�ininkui sekasi blogiau nei komandai." << endl;
    } else {
        rf << "Krep�ininko ir komandos vidurkiai vienodi." << endl;
    }

    // U�darome failus
    df.close();
    rf.close();

    return 0;
}
